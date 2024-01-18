// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O((V+E)logV) & SC : O(V) for Dijkstra's Algorithm.
    // For our case, with 'n' special roads and an 'm×m' grid, TC : O((m^2 + n)logm^2).
    // SC : O(m^2) in the worst-case scenario where all grid points are included in the priority queue and visited set.
    int solve_approach_1(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // Define a lambda function to calculate the Manhattan distance between two points
        auto calculateDistance = [] (int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        // Initialize the answer with a large value
        int ans = INT_MAX;

        // Initialize a priority queue to store the cost and coordinates
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Push the start point into the priority queue with cost 0
        pq.push({0, start[0], start[1]});

        // Initialize a set to store the visited points
        unordered_set<long long> visited;

        // Process until the priority queue is empty
        while (!pq.empty()) {
            // Get the top element from the priority queue
            auto [cost, x, y] = pq.top();
            pq.pop();

            // Calculate the key for the current point
            long long key = 1LL * x * 1e6 + y;

            // If the current point is already visited, skip it
            if (visited.count(key)) {
                continue;
            }

            // Mark the current point as visited
            visited.insert(key);

            // Update the answer with the cost to reach the current point plus the distance to the target
            ans = min(ans, cost + calculateDistance(x, y, target[0], target[1]));

            // For each special road
            for (auto& road : specialRoads) {
                // Get the start and end points and the cost of the special road
                int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], roadCost = road[4];

                // Push the end point of the special road into the priority queue with the cost to reach the start point of the special road plus the cost of the special road
                pq.push({cost + calculateDistance(x, y, x1, y1) + roadCost, x2, y2});
            }
        }

        // Return the minimum cost to reach the target
        return ans;
    }
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        return solve_approach_1(start, target, specialRoads);
    }
};
