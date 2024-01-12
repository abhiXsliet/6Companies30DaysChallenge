// https://leetcode.com/problems/rotate-function/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n) {
        int k = n - 1;
        long long ans = INT_MIN;

        while (k >= 0) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += i * nums[i];
            }

            ans = max(ans, sum);

            int last = nums[n - 1];
            for (int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }
            nums[0] = last;

            k--;
        }
        return (int)ans;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& nums, int n) {
        int sum = 0;
        int rotationSum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // Initial rotation sum 
            rotationSum += i * nums[i];
        }

        int ans = rotationSum;
        // calculate the next rotations sum based on the previous rotation
        for (int k = 1; k < n; k++) {
            rotationSum += sum - n * nums[n - k];
            ans          = max(ans, rotationSum);
        }

        return ans;
    }
public:
    int maxRotateFunction(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        return solve_optimal(nums, nums.size());
    }
};