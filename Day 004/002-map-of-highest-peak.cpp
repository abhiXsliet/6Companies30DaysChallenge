// https://leetcode.com/problems/map-of-highest-peak/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M)
    // SC : O(N*M) Where M = No. of Rows & N = No. of Cols
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int numRows = isWater.size();
        int numCols = isWater[0].size();

        vector<vector<int>> result(numRows, vector<int>(numCols, -1));
        queue<pair<int, int>> que;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (isWater[i][j] == 1) {
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        vector<vector<int>> adjacents = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!que.empty()) {
            int currRows = que.front().first;
            int currCols = que.front().second;
            que.pop();

            for (int i = 0; i < adjacents.size(); i++) {
                int adjRows = currRows + adjacents[i][0];
                int adjCols = currCols + adjacents[i][1];

                if (adjRows >= 0 && adjRows < numRows && adjCols >= 0 && adjCols < numCols) {
                    int currHeight = result[currRows][currCols];

                    if(result[adjRows][adjCols] == -1) {
                        result[adjRows][adjCols] = currHeight + 1;
                        que.push({adjRows, adjCols});
                    }
                }
            }
        }

        return result;
    }
};