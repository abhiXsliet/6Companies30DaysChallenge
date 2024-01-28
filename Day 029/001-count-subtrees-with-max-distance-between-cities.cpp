// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adjacencyList; 
    
    // Takes a starting node, a vector to store distances, and a vector indicating included nodes
    int bfs(int startNode, vector<int>& distances, vector<int>& isNodeIncluded) {
        int nodeCount = distances.size();

        queue<int> nodesQueue; 

        nodesQueue.push(startNode); 

        distances[startNode] = 0; 
        int maxDistance      = 0;
        int farthestNode     = startNode;

        // Continues until all reachable nodes have been explored
        while (!nodesQueue.empty())  { 
            int currentNode = nodesQueue.front();
            nodesQueue.pop(); 
            
            // Iterates through neighbors of the current node
            for (auto nextNode: adjacencyList[currentNode]) {

                // Skips the neighbor if it's not included in the subtree
                if (isNodeIncluded[nextNode] == 0) continue;
                
                // Checks if the neighbor hasn't been visited yet
                if (distances[nextNode] == -1) {
                    // Adds the neighbor to the queue for exploration
                    nodesQueue.push(nextNode);   
                    // Sets the neighbor's distance
                    distances[nextNode] = distances[currentNode] + 1; 
                    
                    // Updates the farthest node and maximum distance if needed
                    if (distances[nextNode] > maxDistance) {
                        maxDistance  = distances[nextNode];
                        farthestNode = nextNode;
                    }
                } 
            } 
        }
        // Returns the node with the farthest distance from the starting node
        return farthestNode; 
    }
public:
    // TC : O(2^n * n^2) 2^n possible states & O(n)-operations per state (e.g., BFS, finding max in a vector) repeated n times.
    // SC : O(n^2) Quadratic due to adjacency list and vectors storing n elements each.
    vector<int> countSubgraphsForEachDiameter(int nodeCount, vector<vector<int>>& edges) {
        adjacencyList.resize(nodeCount);
        for (auto edge: edges){
            adjacencyList[edge[0]-1].push_back(edge[1]-1);
            adjacencyList[edge[1]-1].push_back(edge[0]-1);
        }
        
        // Tracks which nodes are part of the current subtree being considered
        vector<int> isNodeIncluded(nodeCount); 
        // Stores the count of subtrees for each diameter (0 to N-1)
        vector<int> diameterCounts(nodeCount, 0);
        // Stores the shortest distance from a given node to all other nodes
        vector<int> shortestDistances(nodeCount); 

        // This loop iterates through all possible subtrees using a bitmask. Each bit in state represents a node's inclusion.
        for (int state = 1; state < (1 << nodeCount); state++) {
            // Stores the starting node for BFS
            int startNode;
            // Counts nodes in the current subtree
            int nodeCountInCurrentState = 0; 

            // This loop decodes the state bitmask:
            for (int i = 0; i < nodeCount; i++) {
                
                // If i-th bit is 1, mark node (i) as included, set it as starting node, & increment nodeCountInCurrentState
                if ( ((state >> i) & 1) == 1 ) {

                    isNodeIncluded[i] = 1;
                    startNode = i;
                    nodeCountInCurrentState ++;
                }    
                // Otherwise, mark node (i) as not included                
                else isNodeIncluded[i] = 0;
            }
            
            // Reset distances for BFS.
            for (int i = 0; i < nodeCount; i++)
                shortestDistances[i] = -1;

            // Perform BFS from the starting node to find the farthest node
            int farthestNodeFromStart = bfs(startNode, shortestDistances, isNodeIncluded);
            
            // Check if all nodes in the subtree were reachable from the starting node. If not, skip this subtree
            int visitedNodeCount = 0; 
            for (int i = 0; i < nodeCount; i++)
                visitedNodeCount += (shortestDistances[i] != -1);

            if (visitedNodeCount != nodeCountInCurrentState)
                continue;
            
            // Reset distances again for the second BFS
            for (int i = 0; i < nodeCount; i++)
                shortestDistances[i] = -1;

            // Perform BFS from the farthest node to find the diameter
            int farthestNodeFromFarthestNode = bfs(farthestNodeFromStart, shortestDistances, isNodeIncluded);
            
            // Determine the maximum distance (diameter) from the BFS results
            int maxDistance = *max_element(begin(shortestDistances), end(shortestDistances));
            
            // Increment the count for the corresponding diameter
            diameterCounts[maxDistance]++;
        }
        // Ensures that the final result only includes counts for diameters that are actually present in the subtrees
        diameterCounts.erase(begin(diameterCounts));
        return diameterCounts;        
    }
};
