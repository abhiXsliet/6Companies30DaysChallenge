// https://leetcode.com/problems/k-divisible-elements-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // The outer loop and the inner loop each run `n` times, and insertion takes O(log(m)) in set
    // TC : O(N^2 * log(M)) 

    // Set could store all possible subarrays of nums [O(n^2) such subarrays]. 
    // Each subarray is a vector that requires O(n) space.
    // SC : O(N*N)
    int solve_approach_1(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            int count = 0; // count of elements divisible by p
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) {
                    count++;
                }
                if (count <= k) {
                    temp.push_back(nums[j]);
                    st.insert(temp);    // O(log(m))
                }
            }
        }
        return st.size();
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        return solve_approach_1(nums, k, p);
    }
};
