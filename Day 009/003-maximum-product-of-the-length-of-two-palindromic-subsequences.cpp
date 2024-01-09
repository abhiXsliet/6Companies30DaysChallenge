// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)    
    int lcsPalindromic(string& A, string& B) {
        int n = A.length();
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int ans = INT_MIN;
                if(A[i] == B[j]) {
                    ans = 1 + next[j+1];
                } else {
                    ans = max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    // longest palindromic subsequence length
    int answer(string s) {
        string str = s;
        reverse(begin(str), end(str));
        return lcsPalindromic(s, str);
    }
public:
    int maxProduct(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i <= (1 << n); i++) {
            string s1 = "";
            string s2 = "";
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    s1 += s[j];
                }
                else {
                    s2 += s[j];
                }
            }
            ans = max(ans, answer(s1) * answer(s2));
        }
        return ans;
    }
};