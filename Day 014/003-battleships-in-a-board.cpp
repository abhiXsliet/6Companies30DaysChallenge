// https://leetcode.com/problems/battleships-in-a-board/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // These four cases may arise for a battleship
    // 1. If (i == 0 && j == 0) and this cell is 'X', it's a new battleship.
    // 2. If (i == 0) and the previous column is not 'X', it's a new battleship.
    // 3. If (j == 0) and the previous row is not 'X', it's a new battleship.
    // 4. If (i != 0 && j != 0) and neither the previous row nor the previous column has 'X', it's a new battleship.

    // TC : O(M*N)
    // SC : O(1)
    int solve_approach_1(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cntBattleShips = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if ((i == 0 || board[i - 1][j] != 'X') && 
                        (j == 0 || board[i][j - 1] != 'X')) {
                        cntBattleShips ++;
                    }
                }
            }
        }

        return cntBattleShips;
    }

    void DFS(vector<vector<char>>& board, int m, int n, int i, int j) {
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Check for out of bound or if the cell is not part of battleship
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'X')
            return;

        // Mark the current cell as visited
        board[i][j] = '.';

        for (auto& dir : directions) {
            int new_i = dir[0] + i;
            int new_j = dir[1] + j;

            DFS(board, m, n, new_i, new_j);
        }
    }

    // TC : O(M*N)
    // SC : O(M*N) -> Recursive call stack space. 
    //               If at worst all cells == 'X' then dfs would be called for each cell recursively
    int solve_approach_2(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cntBattleShips = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    cntBattleShips ++;
                    DFS(board, m, n, i, j);
                }
            }
        }

        return cntBattleShips;
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        // return solve_approach_1(board);

        return solve_approach_2(board);
    }
};