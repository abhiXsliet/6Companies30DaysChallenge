// https://leetcode.com/problems/bulls-and-cows/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) Where N = string length, at worst every character in the strings could be unique
    string solve_brute(string secret, string guess) {
        // map each elements with its indices
        unordered_map<int, unordered_set<int>> mpp1;
        unordered_map<int, unordered_set<int>> mpp2;

        for (int i = 0; i < secret.length(); i++) {
            int num = secret[i] - '0';
            mpp1[num].insert(i);
        }

        for (int i = 0; i < guess.length(); i++) {
            int num = guess[i] - '0';
            mpp2[num].insert(i);
        }

        int bull = 0;
        int cow  = 0;

        for (auto& it1 : mpp1) {
            int ele = it1.first;

            // check in map2 if the element of map1 is present ? 
            if (mpp2.find(ele) != mpp2.end()) {
                unordered_set<int> mpp1_st = it1.second;
                unordered_set<int> mpp2_st = mpp2[ele];
                
                // store indices of mpp1_st to delete it from the mpp1_st
                vector<int> storeIdx;

                for (auto& idx : mpp1_st) {
                    if (mpp2_st.find(idx) != mpp2_st.end()) {
                        bull ++;
                        mpp2_st.erase(idx);
                        storeIdx.push_back(idx);
                    }
                }

                for (int idx : storeIdx) mpp1_st.erase(idx);
            
                if (mpp1_st.size() != 0 && mpp2_st.size() != 0)
                    cow += min(mpp1_st.size(), mpp2_st.size());
            }
        }
        string result = to_string(bull)+"A"+to_string(cow)+"B";
        return result;
    }

    // TC : O(N) Where N = length of given string
    // SC : O(1)
    string solve_optimal(string secret, string guess) {
        vector<int> secret_freq(10, 0);
        vector<int> guess_freq (10, 0);

        int bull = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull ++;
            }
            else {
                secret_freq[secret[i] - '0'] ++;
                guess_freq [guess[i]  - '0'] ++;
            }
        }

        int cow = 0;
        for (int i = 0; i < 10; i++) {
            cow += min(secret_freq[i], guess_freq[i]);
        }

        string result = to_string(bull) + 'A' + to_string(cow) + 'B';
        return result;
    }
public:
    string getHint(string secret, string guess) {
        // return solve_brute(secret, guess);

        return solve_optimal(secret, guess);
    }
};