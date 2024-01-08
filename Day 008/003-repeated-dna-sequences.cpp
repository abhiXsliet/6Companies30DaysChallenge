// https://leetcode.com/problems/repeated-dna-sequences/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<string> solve_approach_1(string& s, int n) {
        unordered_map<string, int> freq;
        for (int i = 0; i < n-9; i++) {
            freq[s.substr(i, 10)] ++;
        }

        vector<string> result;

        for (auto& it : freq) {
            if (it.second > 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<string> solve_approach_2(string& s, int n) {
        unordered_set<string> freq;
        unordered_set<string> st;

        for (int i = 0; i < n-9; i++) {
            string str = s.substr(i, 10);

            if(freq.find(str) != freq.end() && st.find(str) == st.end()) {
                st.insert(str);
            }
            else {
                freq.insert(str);
            }
        }

        vector<string> result;
        for (string s : st) {
            result.push_back(s);
        }

        return result;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // return solve_approach_1(s, s.length());

        return solve_approach_2(s, s.length());
    }
};