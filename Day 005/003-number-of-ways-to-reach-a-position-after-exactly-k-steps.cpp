// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    // TC : O(k*n) where k is the number of steps and n is the range of positions
    // SC : O(k*n) -> 2D Array used
    long long solve_1(int st, int en, int k, vector<vector<int>>& dp) {
        if (k == 0) {
            return st == en;
        }

        if (dp[k][999+st] != -1) {
            return dp[k][999+st];
        }

        int left  = solve_1(st-1, en, k-1, dp) % MOD;
        int right = solve_1(st+1, en, k-1, dp) % MOD;

        return dp[k][999+st] = (left + right) % MOD;
    }

    // TC : O(k*n) where k is the number of steps and n is the range of positions
    // SC : O(k*n) -> 2D Array used
    long long solve_2(int st, int en, int k, int i, int j, vector<vector<int>>& t) {
        if (i == k && j == en) return 1;
        else if (i == k && j != en) return 0;

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int left  = solve_2(st, en, k, i+1, j-1, t) % MOD;
        int right = solve_2(st, en, k, i+1, j+1, t) % MOD;

        return t[i][j] = (left + right) % MOD;
    }

    int solve_way_1(int startPos, int endPos, int k) {
        vector<vector<int>> dp(k+1, vector<int>(3000, -1));
        
        return solve_1(startPos, endPos, k, dp) % MOD;
    }

    int solve_way_2(int startPos, int endPos, int k) {
        vector<vector<int>> t(k+1, vector<int>(10000, -1));
        startPos = startPos + 1000;
        endPos   = endPos + 1000;
        int i = 0;
        int j = startPos;
        return solve_2(startPos, endPos, k, i, j, t) % MOD;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // return solve_way_1(startPos, endPos, k);

        return solve_way_2(startPos, endPos, k);
    }
};