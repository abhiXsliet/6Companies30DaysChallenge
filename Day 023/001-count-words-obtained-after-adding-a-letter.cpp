// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int transformBinary(string& s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - 'a';
            res = (res | (1 << num));
        }
        return res;
    }
public:
    // TC : O(N * M) Where N = max size of startWords or targetWords which could be at max 5*10^4
    //                     M = max length of chars present in targetWords which could be at max 26 chars
    // SC : O(N) Where N = startWords.size()
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> stringBinary;    
        for (string& s : startWords) {
            int binaryEquivalent = transformBinary(s);
            stringBinary.insert(binaryEquivalent);
        }

        int result = 0;

        for (string& targetWord : targetWords) {
            int binaryEqui = transformBinary(targetWord);

            for (int i = 0; i < targetWord.size(); i++) {
                int num = targetWord[i] - 'a';
                
                // unset the index and check this binary in map
                binaryEqui ^= (1 << num);

                if (stringBinary.find(binaryEqui) != stringBinary.end()) {
                    result ++;
                    break;
                }

                // set the unsetted index
                binaryEqui ^= (1 << num);
            }
        }

        return result;
    }
};