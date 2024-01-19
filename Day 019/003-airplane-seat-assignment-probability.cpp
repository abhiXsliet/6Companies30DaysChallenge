// https://leetcode.com/problems/airplane-seat-assignment-probability/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // If there is only one passenger, he will definitely get his own seat.
        if (n == 1) return 1.0;
        // For n > 1, the nth person getting his own seat is always 0.5.
        // This is because the first person has a 50% chance of taking his own seat or the nth person's seat.
        // If he takes his own seat, everyone will take their own seat, so the nth person will get his own seat.
        // If he takes the nth person's seat, the nth person will not get his own seat.
        else {
            return 0.5;
        }
    }
};
