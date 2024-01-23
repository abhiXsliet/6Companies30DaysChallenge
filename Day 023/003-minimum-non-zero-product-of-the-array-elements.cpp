// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    const ll M = 1e9 + 7;

    // TC : O(log(P))
    // SC : O(log(P)) -> Recursive call stack
    ll pow(ll num, ll p) {
        if (p == 0) return 1;

        ll temp = pow(num, p/2);
        temp = temp % M;

        if (p % 2 == 0) {
            return ((temp * temp) % M);
        }
        else {
            return (((temp * temp) % M) * (num % M)) % M;
        }
    }
public:
    // TC : O(log(P))
    // SC : O(log(P))
    int minNonZeroProduct(int p) {
        ll max = ((1ll << p) - 1);

        ll calPower = pow(max - 1, (max - 1)/2);

        ll result = ((max % M) * (calPower % M)) % M;

        return (int)result;
    }
};