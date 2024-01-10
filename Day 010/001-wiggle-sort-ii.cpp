// https://leetcode.com/problems/wiggle-sort-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    void solve_brute(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));

        vector<int> result(n, 0);

        int j = 1; // pointing at the index of result
        
        for (int i = n - 1; i >= 0; i--) {
            n > 1 ? result[j] = nums[i] : result[j - 1] = nums[i];
        
            j += 2;

            if (j > n-1) {
                j = 0;
            }
        }

        nums = result;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    void solve_better(vector<int>& nums, int n) {
        auto mid_it = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_it, nums.end());
        int middle = *mid_it;

        // defines a macro A(i) that maps the index i to a specific position in the vector. 
        // The expression (n | 1) ensures that the result is odd.
        #define A(i) nums[(1 + (i) * 2) % (n | 1)]

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > middle)
                swap(A(i++), A(j++));
            else if (A(j) < middle) 
                swap(A(j), A(k--));
            else j++;               
        }
    }

    // TC : O(N)
    // SC : O(1)
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;
        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }

    // TC : O(1)
    // SC : O(1)
    int newIndex(int index, int n) {
        return (1 + 2 * index) % (n | 1);
    }

    // TC (Average) : O(N)
    // TC (Worst)   : O(N^2)
    // SC           : O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        k = size - k;
        int start = 0;
        int end = size - 1;
        while (start < end) {
            int pivotIndex = partition(nums, start, end);
            if (pivotIndex < k) {
                start = pivotIndex + 1;
            } else if (pivotIndex > k) {
                end = pivotIndex - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }

    // TC (Average) : O(N)
    // TC (Worst)   : O(N^2)
    // SC           : O(1)
    void solve_optimal(vector<int>& nums, int size) {
        int median = findKthLargest(nums, (size + 1) / 2);
        int left = 0, i = 0, right = size - 1;
        while (i <= right) {
            if (nums[newIndex(i, size)] > median) {
                swap(nums[newIndex(left++, size)], nums[newIndex(i++, size)]);
            } else if (nums[newIndex(i, size)] < median) {
                swap(nums[newIndex(right--, size)], nums[newIndex(i, size)]);
            } else {
                i++;
            }
        }
    }
public:
    void wiggleSort(vector<int>& nums) {
        // solve_brute(nums, nums.size());

        // solve_better(nums, nums.size());

        return solve_optimal(nums, nums.size());
    }
};