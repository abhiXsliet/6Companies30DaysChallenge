// https://leetcode.com/problems/destroying-asteroids/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(1)
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        for (int asteroid : asteroids) {
            if (asteroid <= mass) {
                mass += asteroid;
            }
            else return false;
        }
        return true;
    }
};