// https://leetcode.com/problems/extra-characters-in-a-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^N)
    // SC : O(N)
    int solve_rec(string& s, int n, int idx, unordered_set<string>& st) {
        if (idx >= n) return 0;

        int minExtra     = n;
        string currStr   = "";

        for (int i = idx; i < n; i++) {

            currStr.push_back(s[i]);

            int currExtra   = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int remainExtra = solve_rec(s, n, i+1, st);
            
            int total       = currExtra + remainExtra;

            minExtra        = min(minExtra, total);
        }

        return minExtra;
    }

    // TC : O(N*N)
    // SC : O(N)
    int solve_mem(string& s, int n, int idx, unordered_set<string>& stt, vector<int>& dp) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int minExtra   = n;
        string currStr = "";

        for (int i = idx; i < n; i++) {

            currStr.push_back(s[i]);
            
            int currExtra = (stt.find(currStr) == stt.end()) ? currStr.length() : 0;
            int remainingExtra = solve_mem(s, n, i+1, stt, dp);
            int total = currExtra + remainingExtra;

            minExtra = min(minExtra, total);
        }
        return dp[idx] = minExtra;
    }

    // TC : O(2^N)
    // SC : O(N) -> Recursive Depth
    int solve_recursion(string& s, vector<string>& dictionary) {
        unordered_set<string> st;
        int n = s.length();

        for (string& word : dictionary) {
            st.insert(word);
        }

        return solve_rec(s, n, 0, st);
    }

    // TC : O(N*N) -> N - States * for loop from 0 to n
    // SC : O(N) -> Space of N - States
    int solve_memoization(string& s, vector<string>& dictionary) {
        unordered_set<string> stt;
        for (auto& word : dictionary) 
            stt.insert(word);

        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve_mem(s, n, 0, stt, dp);
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        // return solve_recursion(s, dictionary);

        return solve_memoization(s, dictionary);
    }
};