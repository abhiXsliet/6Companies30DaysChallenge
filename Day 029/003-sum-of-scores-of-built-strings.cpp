// https://leetcode.com/problems/sum-of-scores-of-built-strings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) Where N = length of the string
    vector<int> z_func(string s) {
        int n = s.length();
        vector<int> z(n);
        for (int i = 1, left = 0, right = 0; i < n; i++) {
            if (i <= right) 
                z[i] = min(right - i + 1, z[i - left]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
                z[i]++;
            
            if (i + z[i] - 1 > right) 
                left = i, right = i + z[i] - 1;
        }
        return z;
    }

    // TC : O(N)
    // SC : O(N) Where N = length of the string
    long long solve_approach_1(string& s) {
        vector<int> arr = z_func(s);
        long long sum = s.size();
        for (int i = 1; i < s.size(); i++) {
            long long x = arr[i];
            sum  = sum + x;
        }
        return sum;
    }
public:
    long long sumScores(string s) {
        return solve_approach_1(s);
    }
};