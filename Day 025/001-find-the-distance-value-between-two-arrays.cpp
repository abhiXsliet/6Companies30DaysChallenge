// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M*N)
    // SC : O(1)
    int solve_brute(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            bool flag = 1;
            for (int j = 0; j < n; j++) {
                if (abs(arr1[i] - arr2[j]) > d)
                    continue;
                else flag = 0;
            }

            if (flag) ans++;
        }
        return ans;
    }

    // TC : O(log M), where M is the size of the array.
    // SC  : O(1)
    int lowerBound(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    // TC : O(N * log M), where N is the size of arr1 and M is the size of arr2.
    // SC : O(1)
    int solve_optimal(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for(auto num : arr1){
            int low = num - d;
            int high = num + d;
            int lowIndex = lowerBound(arr2, low);
            int highIndex = lowerBound(arr2, high);
            if (lowIndex == highIndex && 
                (lowIndex == arr2.size() || 
                (arr2[lowIndex] != low && arr2[lowIndex] != high))) {
                count++;
            }
        }
        return count;
    }


public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // return solve_brute(arr1, arr2, d);

        return solve_optimal(arr1, arr2, d);
    }
};