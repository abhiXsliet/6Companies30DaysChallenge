// https://leetcode.com/problems/top-k-frequent-words/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first;
        }
    };

    // where m = unique words. Insertion/Extraction into a pq takes O(log m)
    // TC : O(n + m log m + k log m)
    // SC : O(m + k)
    vector<string> solve_approach_1(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto& word : words) {
            mpp[word]++;
        }
        
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for (auto& it : mpp) { // O(M * log(M))
            pq.push({it.second, it.first}); // O(log(M))
        }

        vector<string> result;
        while(k-- && !pq.empty()) { //O(k * log(M))
            string word = pq.top().second;
            result.emplace_back(word);
            pq.pop();
        }
        return result;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    vector<string> solve_approach_2(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto& word : words) {
            mpp[word]++;
        }
        
        vector<string> result;
        
        for (auto& it : mpp) {
            result.emplace_back(it.first);
        }   

        auto cmp = [&](string& a, string& b) {
            if (mpp[a] == mpp[b]) return a < b;
            return mpp[a] > mpp[b];
        };

        sort(begin(result), end(result), cmp);

        result.erase(begin(result) + k, end(result));
        return result;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // return solve_approach_1(words, k);

        return solve_approach_2(words, k);
    }
};