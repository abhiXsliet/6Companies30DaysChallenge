// https://leetcode.com/problems/construct-the-longest-new-string/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_brute(int x, int y, int z) {
        int maxLen = 0;

        int AAs_cnt  = 0;
        int BBs_cnt  = 0;

        while (x > 0 && y > 0) {
            AAs_cnt += 2;
            BBs_cnt += 2;

            x--;
            y--;
        }

        if (x > 0) AAs_cnt ++;
        if (y > 0) BBs_cnt ++;

        maxLen  = max(AAs_cnt, BBs_cnt);
        maxLen += z;
        maxLen  = 2*maxLen;

        return maxLen;
    }

    // TC : O(1)
    // SC : O(1)
    int solve_optimal(int x, int y, int z) {
        if (x > y) // x y x
            x = y + 1;
        else if (y > x) // y x y
            y = x + 1;

        return 2*(x+y+z);
    }
public:
    int longestString(int x, int y, int z) {
        // return solve_brute(x, y, z);

        return solve_optimal(x, y, z);
    }
};