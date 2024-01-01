// https://leetcode.com/problems/query-kth-smallest-trimmed-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(Q * N * log N), where Q = no. of queries, N = no. of numbers, and log(N) for sorting vector of pairs
    // SC : O(N)
    vector<int> solve_approach_1(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result; 
        for(auto query: queries) {

            priority_queue<pair<string,int>> trimmed_numbers; 

            for(int i=0; i<nums.size(); i++) {
                
                int trim_length       = query[1];
                int start_index       = nums[i].length() - trim_length; 
                string trimmed_number = nums[i].substr(start_index, trim_length); 

                if(trimmed_numbers.size() < query[0]) {
                    trimmed_numbers.push({trimmed_number, i}); 
                }
                else {
                    if(trimmed_numbers.top().first > trimmed_number) {
                        trimmed_numbers.pop();
                        trimmed_numbers.push({trimmed_number, i}); 
                    }
                }
            }
            int smallest_index = trimmed_numbers.top().second; 
            result.push_back(smallest_index); 
        }
        return result; 
    }
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        return solve_approach_1(nums, queries);
    }
};
