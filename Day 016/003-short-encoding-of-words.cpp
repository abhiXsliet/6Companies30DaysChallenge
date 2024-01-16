// https://leetcode.com/problems/short-encoding-of-words/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N*M) N = words.size() & M = string.length() of each word
    int solve_approach_1(vector<string>& words) {
        auto cmp = [&](string a, string b) {
            return b.length() < a.length();
        };

        sort(begin(words), end(words), cmp);
        for (auto& wo : words) cout << wo << " ";
        cout << endl;
        string result = "";

        for (string& str : words) {
            // Check if the word is already included in the encoding
            if (result.find(str + "#") == string::npos) {
                result += str + "#";
            }
        }

        return result.length();
    }

    // TC : O(N*M) Where N = words.size() & M = words[i].length()
    // SC : O(N)
    int solve_approach_2(vector<string>& words) {
        set<string> st1(begin(words), end(words));

        for (auto& it : st1) {
            for(int i = 1; i < it.length(); i++) {
                // delete the substring starting from index-1 in st2
                st1.erase(it.substr(i));
            }
        }

        int encodedLen = 0;
        for (auto& it : st1) {
            encodedLen += it.length() + 1;    // +1 for '#'
        }

        return encodedLen;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        // return solve_approach_1(words);

        return solve_approach_2(words);
    }
};