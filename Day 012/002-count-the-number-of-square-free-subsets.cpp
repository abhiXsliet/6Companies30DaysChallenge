// https://leetcode.com/problems/count-the-number-of-square-free-subsets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int M = 1e9 + 7;

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<vector<int>> dp;

    ll convertFromMask(int mask) {
        ll result = 1;
        for (int j = 0; j < primes.size(); j++) {
            if (mask & (1 << j))
                result *= primes[j];
        }
        return result;
    }

    int convertToMask(ll x) {
        int mask = 0;
        for (int j = 0; j < primes.size(); j++) {
            if (x % primes[j] == 0) {
                x /= primes[j];
                mask |= (1 << j);
            }
        }
        return mask;
    }

    // TC : O(N*1024)
    // SC : O(N*1025)
    int cntSubsets(int idx, int mask, vector<int>& nums) {
        int n = nums.size();

        if (mask == 0) return 1;
        if (idx == n) return 0;

        if (dp[idx][mask] != -1) return dp[idx][mask];

        ll X = convertFromMask (mask);

        int ans = cntSubsets (idx + 1, mask, nums);
        if (X % nums[idx] == 0)
            ans = (ans + cntSubsets(idx+1, convertToMask(X / nums[idx]), nums)) % M;
        
        return dp[idx][mask] = ans;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> store_except_1;
        int cntOne = 0;
        for (int num : nums) {
            if (num == 1) cntOne ++;
            else store_except_1.push_back(num);
        }

        dp.clear();
        int n = store_except_1.size();
        dp.resize(n, vector<int>(1025, -1));

        // subsets containing only 1s
        ll one_subsets = 1;
        while (cntOne--) {
            one_subsets = (one_subsets * 2) % M;
        }
        one_subsets = (one_subsets - 1 + M) % M;

        ll other_subsets = 0;
        for (int mask = 1; mask < 1024; mask++) {
            other_subsets = (other_subsets + cntSubsets(0, mask, store_except_1)) % M;
        }

        ll result = (one_subsets + other_subsets) % M;
        result = (result + other_subsets * one_subsets) % M;

        return result;
    }
};