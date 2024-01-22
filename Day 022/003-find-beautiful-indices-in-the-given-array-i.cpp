// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> prefixStore(string s) {
        int n = s.length();
        vector<int> prefix_idx(n, 0);

        for (int i = 1; i < n; i++) {
            int j = prefix_idx[i - 1];

            while (j > 0 && s[i] != s[j]) {
                j = prefix_idx[j - 1];
            }

            if (s[i] == s[j]) j ++;
            prefix_idx[i] = j;
        }
        return prefix_idx;
    }
    
    // TC : O(M + N) Where M & N = length of string pattern & text respectively
    // SC : O(M)  
    vector<int>search(string pat, string txt) {
        vector<int> prefix = prefixStore(pat);
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++, j++;
            }
            else {
                if (j != 0) {
                    j = prefix[j - 1];
                }
                else {
                    i ++;
                }
            }
            
            if (j == pat.size()) {
                result.push_back(i - j);
                j = prefix[j - 1];
            }
        }
        return result;
    }
public:
    // TC : O((M + N) + (P + Q) * (R * S)) 
    // Where R & S = size of storeIndices_a, storeIndices_b
    // O(M + N) = due to 1st search fn call where M & N = a & b string length respectively
    // O(P + Q) = due to 2nd search fn call where P & Q = a & b string length respectively

    // SC : O(M + N)
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> storeIndices_a = search(a, s);
        vector<int> storeIndices_b = search(b, s);

        vector<int> result;

        for (int idx_a : storeIndices_a) {
            for (int idx_b : storeIndices_b) {
                if (abs(idx_a - idx_b) <= k) {
                    result.push_back(idx_a);
                    break; 
                }
            }
        }
        return result;
    }
};