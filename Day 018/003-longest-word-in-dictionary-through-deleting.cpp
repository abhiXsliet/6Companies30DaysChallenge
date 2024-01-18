// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M) Where M = s.length()
    // SC : O(1) 
    bool isSubsequence(string s, string str) {
        int i = 0, j = 0;
        int m = s.length();
        int n = str.length();

        // If 'str' is longer than 's', it cannot be a subsequence
        if (n > m) return false;

        // Iterate over 's' and 'str'
        while (i < m && j < n) {
            // If characters match, move to next character in 'str'
            if (s[i] == str[j]) j++;
            // Always move to next character in 's'
            i++;
        }

        // If all characters of 'str' were found in 's', return true
        return j == n;
    }

    // TC : O(N*log(N) + M*N) Where M = length of string and N = No. no. of words
    string solve_approach_1(string s, vector<string>& dictionary) {
        string result = "";
        
        auto cmp = [&](string a, string b) {
            return a.length() == b.length() ? a < b : b.length() < a.length();
        };

        sort(begin(dictionary), end(dictionary), cmp);

        for (string& str : dictionary) {
            if (isSubsequence(s, str)) {
                return result = str;
            }
        }
        return result;
    }
    
    // TC : O(M*N) Where M = s.length() & N = No. of words/dictionary.size() 
    // SC : O(1)
    string solve_approach_2(string s, vector<string>& dictionary) {
        string result = "";
        
        for (string& str : dictionary) {
            // If 'str' is a subsequence of 's' and is longer than the current result
            // or is the same length but lexicographically smaller, update the result
            if (isSubsequence(s, str) && (result.size() < str.size() 
                                      || (result.size() == str.size() && str < result))) {
                result = str;
            }
        }
        return result;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // return solve_approach_1(s, dictionary);

        return solve_approach_2(s, dictionary);
    }
};
