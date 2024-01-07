// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/



#include <bits/stdc++.h>
using namespace std;

// --------------------------------------- Solution - 1 : (BRUTE FORCE) ----------------------------------------------------------------
// TC (at worst): O(100*2000*2000) ~= O(4*10^8) -> TLE
// SC (at worst): O(100*2000*2000) ~= O(4*10^8)

class Solution {
public:
    vector<vector<int>> storeIndices;
    Solution(vector<vector<int>>& rects) {
        for (auto rect : rects) {
            for (int x = rect[0]; x <= rect[2]; x++) {
                for (int y = rect[1]; y <= rect[3]; y++) {
                    storeIndices.push_back({x, y});
                }
            }
        }
    }
    
    vector<int> pick() {
        int rand_idx = rand() % storeIndices.size();
        return storeIndices[rand_idx];
    }
};


// ---------------------------------------- Solution - 2 : (OPTIMAL) --------------------------------------------------------------------

// TC : O(N*log(N))
// SC : O(N)

class Solution {
public:
    vector<int> rect_cummulative_sum;
    vector<vector<int>> rects;
        
    // count the no. of points of each rectangle
    int pointsCnt = 0;
    Solution(vector<vector<int>>& rects) {
        this -> rects = rects;

        for (auto& rect : rects) {
            pointsCnt += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);

            rect_cummulative_sum.push_back(pointsCnt);
        }
    }
    
    // TC : O(log(N))
    vector<int> pick() {
        int pic_randomIdx = rand() % pointsCnt;
        
        // low holds the correct indices after loop termination
        int low  = 0;
        int high = rects.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (rect_cummulative_sum[mid] <= pic_randomIdx) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        vector<int> rect = rects[low];
        // we get the x1, x2, y1, y2 of the respective rectangle from rect
        int x1 = rect[0];
        int x2 = rect[2];
        int y1 = rect[1];
        int y2 = rect[3];

        // random value of x could be from 0 to (x2 - x1 + 1)
        int rand_x = rand() % (x2-x1 + 1);
        // random value of y could be from 0 to (y2 - y1 + 1)
        int rand_y = rand() % (y2-y1 + 1);

        return {x1 + rand_x, y1 + rand_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */