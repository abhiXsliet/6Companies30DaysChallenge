// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;

        // <---------
        for (int& i : left) {
            // Update 'result' with the maximum of current 'result' and position of the ant
            // This gives the maximum time for an ant to fall off the left end
            result = max(result, i);
        }

        // --------->
        for (int& i : right) {
            // Update 'result' with maximum of 'result' & distance of ant from the right end (n - i)
            // This gives the maximum time for an ant to fall off the right end
            result = max(result, n - i);
        }
        // Return the maximum time for any ant to fall off the plank
        return result;
    }
};