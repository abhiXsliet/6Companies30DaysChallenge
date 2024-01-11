// https://leetcode.com/problems/largest-divisible-subset/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(k^2), where k is the size of the subset.
    bool isValidSubset(vector<int>& subset) {
        for (int i = 0; i < subset.size(); ++i) {
            for (int j = 0; j < subset.size(); ++j) {
                if (i != j && subset[i] % subset[j] != 0 && subset[j] % subset[i] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // TC: O(2^n * n^2), where n is the size of the input array nums.
    // SC: O(n), where n is the size of the input array nums.
    vector<int> solve_brute(vector<int>& nums, int n) {
        vector<int> t;
        for (long long p = 0; p < (1 << n); p++) {
            vector<int> subsets;
            for (int i = 0; i < n; i++) {
                long long power = 1 << i;
                if (p & power) {
                    subsets.push_back(nums[i]);
                }
            }

            if (isValidSubset(subsets) && subsets.size() > t.size()) {
                t = subsets;
            }
        }
        return t;
    }

    // TC : O(N^2)
    // SC : O(N)
    vector<int> solveOptimal(int n, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1), parent(n, -1);
        int max_size = 0, max_val_idx = 0;

        // Compute the length of the longest divisible subset
        for (int curr = 0; curr < n; ++curr) {
            for (int prev = 0; prev < curr; ++prev) {
                if (nums[curr] % nums[prev] == 0 && dp[prev] + 1 > dp[curr]) {
                    dp[curr] = dp[prev] + 1;
                    parent[curr] = prev;
                }
            }
            if (dp[curr] > max_size) {
                max_size = dp[curr];
                max_val_idx = curr;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> answer;
        while (max_val_idx != -1) {
            answer.push_back(nums[max_val_idx]);
            max_val_idx = parent[max_val_idx];
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        return solveOptimal(nums.size(), nums);
    }
};