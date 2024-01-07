// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC (Average) : O(N)
    // TC (Worst)   : O(N^2) -> when array is already sorted or reverse sorted
    // SC           : O(log(N)) -> Recursive Depth
    int quickSelect(vector<int>& nums, int left, int right, int n) {
        if (left == right) return nums[left];

        int pivot_idx = rand() % (right - left + 1) + left;

        pivot_idx     = partition(nums, left, right, pivot_idx);

        if (n == pivot_idx) return nums[n];
        else if (n < pivot_idx) 
            return quickSelect(nums, left, pivot_idx - 1, n);
        else 
            return quickSelect(nums, pivot_idx + 1, right, n);
    }
    
    // TC : O(N)
    // SC : O(1)
    int partition(vector<int>& nums, int left, int right, int pivot_idx) {
        int pivot = nums[pivot_idx];
        
        swap(nums[pivot_idx], nums[right]);

        int storeIdx = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] < pivot) {
                swap(nums[storeIdx ++], nums[i]);
            }
        }

        swap(nums[storeIdx], nums[right]);

        return storeIdx;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));

        int targetNum = nums[n >> 1];
        int result = 0;

        for (int num : nums) {
            result += abs(targetNum - num);
        }

        return result;
    }

    // TC : O(N) + O(k*log(N))
    // SC : O(N)
    int solve_better(vector<int>& nums, int n) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) pq.push(num);

        int median_idx = n/2;
        
        while(median_idx --) pq.pop();
        
        int median_ele = pq.top();

        int cntMove = 0;
        for (int num : nums) {
            cntMove += abs(median_ele - num);
        }        
        return cntMove;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal_1(vector<int>& nums, int n) {
        int medianEle = quickSelect(nums, 0, n - 1, n / 2);
        int moveCnt = 0;
        for (int num : nums) {
            moveCnt += abs(medianEle - num);
        }

        return moveCnt;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal_2(vector<int>& nums, int n) {
        // STL for QuickSelect => O(N)
        nth_element(begin(nums), begin(nums) + n / 2, end(nums));

        int medianEle = nums[n >> 1];

        int moveCnt = 0;
        for (int num : nums) {
            moveCnt += abs(medianEle - num);
        }

        return moveCnt;
    }
public:
    int minMoves2(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_better(nums, nums.size());

        // return solve_optimal_1(nums, nums.size());

        return solve_optimal_2(nums, nums.size());
    }
};