// https://leetcode.com/problems/letter-combinations-of-a-phone-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(4^N) Where N = length of the input string digits
    // SC : O(N) -> Recursive Depth
    void solve(string digits, int idx, string mapping[], string output, vector<string>& result) {
        if (idx == digits.size()) {
            result.push_back(output);
            return;
        }

        int get_num = digits[idx] - '0';
        string str  = mapping[get_num];

        for (int i = 0; i < str.length(); i++) {
            output += str[i];
            solve(digits, idx+1, mapping, output, result);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();

        if (n == 0)
            return {};

        vector<string> result;
        string output = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, 0, mapping, output, result);

        return result;
    }
};