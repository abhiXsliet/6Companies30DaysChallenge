// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool isIncreasingSubArray(vector<int>& nums, int n, int start, int end) {
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (i <= end && i >= start) {
                continue;
            }
            if (nums[i] <= prev) {
                return false;
            }
            prev = nums[i];
        }
        return true;
    }
public:
    // TC : O(N^3)
    // SC : O(1)
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isIncreasingSubArray(nums, n, i, j)) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};