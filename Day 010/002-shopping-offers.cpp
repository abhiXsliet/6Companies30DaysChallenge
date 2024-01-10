// https://leetcode.com/problems/shopping-offers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx, int n) {
        if (idx >= special.size()) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                s += needs[i] * price[i];
            }
            return s;
        }

        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (special[idx][i] > needs[i]) {
                flag = 1;
            }
        }

        if (flag == 0) {
            for (int i = 0; i < n; i++) {
                needs[i] -= special[idx][i];
            }
            int consider = special[idx][n] + solve(price, special, needs, idx, n);
            for (int i = 0; i < n; i++) {
                needs[i] += special[idx][i];
            }
            return min(consider, solve(price, special, needs, idx+1, n));
        }

        return solve(price, special, needs, idx+1, n);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs, 0, price.size());
    }
};