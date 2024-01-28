// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Directions for exploring the neighboring cells in the grid
    vector<int> directions {-1, 0, 1, 0, -1};
    int m, n;

    // Function that counts the number of islands in the grid
    int countIslands(vector<vector<int>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1) {

                    dfs(i, j, grid);
                    ++numIslands;
                }
            }
        }

        // Reset the grid to its original state
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return numIslands;
    }

    // Depth-first search to explore an island
    void dfs(int i, int j, vector<vector<int>>& grid) {
        // Mark the current cell as visited
        grid[i][j] = 2; 

        for (int k = 0; k < 4; ++k) {

            int x = i + directions[k];
            int y = j + directions[k + 1];

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }

    // TC : O((N*M)^2)
    // SC : O(N*M)
    int solve_approach_1(vector<vector<int>>& grid) {
        // If the grid is already disconnected, return 0
        if (countIslands(grid) != 1) {
            return 0;
        }

        // Try removing each island and check if the grid becomes disconnected
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1) {

                    grid[i][j] = 0;

                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    
                    grid[i][j] = 1;
                }
            }
        }

        // If removing any single island doesn't disconnect the grid, then removing any two islands will
        return 2;

    }
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return solve_approach_1(grid);
    }
};
