// https://leetcode.com/problems/count-number-of-nice-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> nums, int k, int n) {
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            }
            else {
                nums[i] = 1;
            }
        }

        int no_of_subarrays = 0;
        
        // map store the {prefixSum, count of prefixSum}
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            no_of_subarrays += mpp[sum - k];
            mpp[sum]++;
        }
        return no_of_subarrays;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> nums, int k, int n) {
        vector<int> freq(n+1);
        freq[0] = 1;

        int sum = 0;
        int no_of_subArrays = 0;

        for (int num : nums) {
            // Doing '&' with any number tell wheather the no. is odd or even
            sum += num & 1;

            if (sum - k >= 0) 
                no_of_subArrays += freq[sum - k];

            freq[sum] ++;
        }

        return no_of_subArrays;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return approach_1(nums, k, nums.size());

        return approach_2(nums, k, nums.size());
    }
};