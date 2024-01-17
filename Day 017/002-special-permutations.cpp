// https://leetcode.com/problems/special-permutations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    vector<vector<int>> dp;

    // TC : O(N)
    // SC : O(1)
    bool isSpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (!(nums[i] % nums[i + 1] == 0 || nums[i + 1] % nums[i] == 0))
                return false;
        }
        return true;
    }

    // TC : O(N! * N)
    // SC : O(N)
    void brute_1(vector<int>& nums, int n, int idx, int& ans) {
        if (idx >= n) {
            if (isSpecial(nums))
                ans ++;
            return;
        }            

        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            brute_1(nums, n, idx+1, ans);
            swap(nums[i], nums[idx]);
        }
    }

    // TC : O(N! * N)
    // SC : O(N)
    int brute_2(vector<int>& nums, int n, vector<bool>& visited, int prevIdx, int count) {
        if (count == n) return 1;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (prevIdx == -1 || 
               ( nums[i] % nums[prevIdx] == 0 || nums[prevIdx] % nums[i] == 0)))  {

                visited[i] = true;
                ans = (ans + brute_2(nums, n, visited, i, count + 1)) % M;
                visited[i] = false;
            }    
        }
        return ans;
    }

    // TC : O(N * 2^N)    
    // SC : O(2^N * N) because we are storing results for each state of the mask & for each element in the dp table
    int optimal_1(vector<int>& nums, int n, int mask, int last) {
        //  If all numbers are used (i.e., all bits in the mask are set)
        if (mask == (1 << n) - 1) 
            return 1;  // one valid permutation found

        if (dp[mask][last] != -1) 
            return dp[mask][last];
        
        int ans = 0;
        // Try to add each element in the permutation
        for (int i = 0; i < n; i++) {
            // If the i-th number is not used (i.e., the i-th bit in the mask is not set) 
            // and it can be placed next to the last number 
            // (i.e., either nums[last] is divisible by nums[i] or vice-versa)
            if (!(mask & (1 << i)) && (nums[last] % nums[i] == 0 || nums[i] % nums[last] == 0)) {
                // It adds the number of valid permutations obtained by setting the i-th bit in the mask 
                // (i.e., using the i-th number next) and updating the last number to the i-th number
                ans = (ans + optimal_1(nums, n, mask | (1 << i), i)) % M;
            }
        }
        
        return dp[mask][last] = ans;
    }

    // TC : O(N * 2^N)    
    // SC : O(2^N * N) 
    int optimal_2(vector<int>& nums, int n, int mask, int prevIdx, int count, vector<vector<int>>& dp) {
        // All numbers are used (i.e., all bits of mask is set)
        if (count == n) return 1;

        if (dp[mask][prevIdx] != -1)
            return dp[mask][prevIdx];

        int ans = 0;

        for (int i = 0; i < n; i++) {
             
            if (!(mask & (1 << i)) && (mask == 0 
                || nums[i] % nums[prevIdx] == 0 
                || nums[prevIdx] % nums[i] == 0))  {

                ans = (ans + optimal_2(nums, n, mask | (1 << i), i, count + 1, dp)) % M;
            }
        }

        return dp[mask][prevIdx] = ans;
    }

    // TC : O(N! * N)
    // SC : O(N)
    int solve_brute_1(vector<int>& nums) {
        int ans = 0;
        brute_1(nums, nums.size(), 0, ans);
        ans = ans % M;
        return ans;
    }

    // TC : O(N! * N)
    // SC : O(N)
    int solve_brute_2(vector<int>& nums) {
        int n = nums.size();
        // last taken element idx
        int prevIdx = -1;
        // store no. of taken elements
        int count   = 0;
        vector<bool> visited(n, 0);
        return brute_2(nums, n, visited, prevIdx, count);
    }
    
    // 2^n states for the mask and for each state, we are doing O(n) work to check all elements. 
    // So, the total time complexity is O(n∗2^n) and we are calling (optimal_1) function n times thus final
    // TC : O(N^2 * 2^N)     
    // SC : O(2^N * N) size of dp table
    int solve_optimal_1(vector<int>& nums) {
        int n = nums.size();
        // i-th bit is set if the i-th number is used
        dp = vector<vector<int>>(1 << n, vector<int>(n, -1));
        int ans = 0;

        // O(N)
        for (int i = 0; i < n; i++) {
            // O(N * 2^N)
            ans = (ans + optimal_1(nums, n, 1 << i, i)) % M;
        }
        return ans;
    }

    int solve_optimal_2(vector<int>& nums) {
        int n = nums.size();
        // last taken element since (-1) can't be accessed in bit
        int prevIdx = 0;

        // store no. of taken elements
        int count   = 0;

        // we can replace the visited array with the mask of length of n (i.e., 14)
        int mask = 0;   

        // size of dp required : (2^n, n)
        vector<vector<int>> dp((1 << n), vector<int>(n, -1));

        return optimal_2(nums, n, mask, prevIdx, count, dp);
    }
public:
    int specialPerm(vector<int>& nums) {
        // return solve_brute_1(nums);

        // return solve_optimal_1(nums);

        // return solve_brute_2(nums);

        return solve_optimal_2(nums);
    }
};