// https://leetcode.com/problems/stone-game-vi/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    int solve_approach_1(vector<int> & aliceVal, vector<int>& bobVal) {
        int n = aliceVal.size();
        vector<vector<int>> store;

        for (int i = 0; i < n; i++) {
            store.push_back({aliceVal[i] + bobVal[i], aliceVal[i], bobVal[i]});
        }

        sort(begin(store), end(store), greater<vector<int>>());

        int alicePoints = 0;
        int bobPoints   = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                alicePoints += store[i][1];
            }
            else {
                bobPoints += store[i][2];
            }
        }

        if (alicePoints < bobPoints) return -1;
        else if (alicePoints > bobPoints) return 1;
        return 0;
    }
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        return solve_approach_1(aliceValues, bobValues);
    }
};