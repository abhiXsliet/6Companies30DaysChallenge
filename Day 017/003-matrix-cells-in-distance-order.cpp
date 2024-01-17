// https://leetcode.com/problems/matrix-cells-in-distance-order/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M log(N*M)) Where N = Rows & M = Cols
    // SC : O(N*M)
    // APPROACH - 1 : USING SORTING
    vector<vector<int>> solve_approach_1(int rows, int cols, int rC, int cC) {
        vector<vector<int>> result;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int dist = abs(rC - i) + abs(cC - j);

                result.push_back({i, j, dist});
            }
        }   

        auto cmp = [&](vector<int> a, vector<int> b) {
            // sorting a/c from the smallest distance to the largest distance
            return a[2] < b[2];
        };

        sort(begin(result), end(result), cmp);

        for (auto& vec : result) {
            vec.pop_back();
        }

        return result;
    }

    // TC : O(N*M log(N*M)) Where N = Rows & M = Cols
    // SC : O(N*M)
    // APPROACH - 2 : USING HEAP
    vector<vector<int>> solve_approach_2(int rows, int cols, int rC, int cC) {

        auto cmp = [&](vector<int> a, vector<int> b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp) > pq(cmp); 

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int dist = abs(rC - i) + abs(cC - j);

                pq.push({i, j, dist});
            }
        }

        vector<vector<int>> result;

        while(!pq.empty()) {
            vector<int> vec = pq.top();
            pq.pop();

            // remove the distance from all vectors
            vec.pop_back();

            result.push_back(vec);
        }

        return result;
    }

    // TC : O(N*M) Where N = Rows and M = Cols
    // SC : O(N*M)
    // APPROACH - 2 : USING BFS
    vector<vector<int>> solve_approach_3(int rows, int cols, int rC, int cC) {
        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

        vector<vector<int>> result;
        queue<vector<int>> que;

        que.push({rC, cC});
        visited[rC][cC] = 1;

        while (!que.empty()) {
            vector<int> vec = que.front();
            que.pop();

            result.push_back(vec);

            for (auto dir : directions) {
                int newRow = vec[0] + dir[0];
                int newCol = vec[1] + dir[1];

                if (newRow >= 0 && newRow < rows && 
                    newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    
                    que.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }

        return result;
    }

public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        // return solve_approach_1(rows, cols, rCenter, cCenter);

        // return solve_approach_2(rows, cols, rCenter, cCenter);

        return solve_approach_3(rows, cols, rCenter, cCenter);
    }
};