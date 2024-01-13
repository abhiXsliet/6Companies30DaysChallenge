// https://leetcode.com/problems/maximum-length-of-repeated-subarray/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3) -> TLE
    // SC : O(N)
    int solve_brute(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> temp;
                for (int k = i; k <= j; k++) {
                    temp.push_back(nums1[k]);
                }
                st.insert(temp);
            }
        }

        int len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                vector<int> temp;
                for (int k = i; k <= j; k++) {
                    temp.push_back(nums2[k]);
                }

                if (st.find(temp) != st.end()) {
                    len = max(len, (int)temp.size());
                }
            }
        }

        return len;
    }

    // TC : O(N*M)
    // SC : O(N*M)
    int solveTab(int n, int m, vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // count the max subarray size of repeated subarrays
        int maxi = INT_MIN;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] =  1 + dp[i+1][j+1];
                } 

                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // return solve_brute(nums1, nums2, n, m);

        return solveTab(n, m, nums1, nums2);
    }
};