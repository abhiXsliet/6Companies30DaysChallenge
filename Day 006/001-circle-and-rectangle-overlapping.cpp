// https://leetcode.com/problems/circle-and-rectangle-overlapping/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int near_x = max(min(x2, xCenter), x1);
        int near_y = max(min(y2, yCenter), y1);

        int dist_x = near_x - xCenter;
        int dist_y = near_y - yCenter;

        return ((dist_x * dist_x) + (dist_y * dist_y)) <= (radius * radius);
    }
};