// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int gcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;

        while (a != b) {
            if (a > b) {
                a -= b; 
            }
            else b -= a;
        }
        return a;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int minimizeSet(int d1, int d2, int uC1, int uC2) {
        ll lcm  = ((ll)d1 * (ll)d2) / gcd(d1, d2);
        
        ll low  = 1; 
        ll high = 2*1e9;
        ll ans  = high;

        while (low <= high) {
            ll mid = high + (low - high) / 2;

            // no.s which is not divisible by d1
            int cnt1 = (int)(mid - (mid / d1));
            // no.s which is not divisible by d2
            int cnt2 = (int)(mid - (mid / d2));
            // no.s which is not divisible by both d1 and d2
            int cnt3 = (int)(mid - (mid / lcm));
        
            if (cnt1 < uC1 || cnt2 < uC2 || cnt3 < (uC1 + uC2)) {
                low = mid + 1;
            }
            else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }

        return (int) ans;
    }
};