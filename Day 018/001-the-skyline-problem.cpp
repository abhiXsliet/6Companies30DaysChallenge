// https://leetcode.com/problems/the-skyline-problem/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<vector<int>> solve_approach_1(vector<vector<int>>& buildings) {
        vector<pair<int, int>> vec;

        for (auto& building : buildings) {
            // push the left and -ve height of the building 
            vec.push_back({building[0], -building[2]});
            // push the right and +ve height of the building 
            vec.push_back({building[1],  building[2]});
        }

        sort(begin(vec), end(vec));
        
        multiset<int> mst;
        mst.insert(0);

        vector<vector<int>> result;
        int prev = 0;
        int curr = 0;
        
        for (auto& v : vec) {
            if (v.second < 0) {
                mst.insert(-v.second);
            }
            else { // we encountered a right coordinate with their distance
                mst.erase(mst.find(v.second));
            }

            curr = *mst.rbegin();
            if (prev != curr) {
                result.push_back({v.first, curr});
                prev = curr;
            }
        }

        return result;
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return solve_approach_1(buildings);
    }
};