// https://leetcode.com/problems/the-number-of-good-subsets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    const int M = 1e9 + 7;
    vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    ll freq[31] = {0};
    int t[31][1024];
    
    // TC : O(n * 2^m), where n is the size of the input array and m is the number of prime numbers less than or equal to 30
    // SC : O(n * 2^m), due to the use of the dynamic programming table t which has dimensions of n and 2^m
    int findGoodSubsets(int val, int mask) {
        if (val > 30) return mask > 0;
        
        if (t[val][mask] != -1) return t[val][mask] % M;

        ll newMask = 0;
        ll product = 1;

        for (int i = 0; i < primes.size(); i++) {

            if ((val % primes[i]) == 0) {

                product *= (primes[i]);
                newMask |= (1 << i);
            }
        }

        ll ans = findGoodSubsets(val + 1, mask);
        if (product == val && freq[val] && ((mask & newMask) == 0)) {
            
            ans += ( (findGoodSubsets(val + 1, mask | newMask)) * (freq[val]) ); 
        }

        return t[val][mask] = ans % M;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        for (int num : nums) freq[num] ++;

        memset(t, -1, sizeof(t));

        ll val = findGoodSubsets(2, 0) % M;

        ll one_cnt = 1;
        for (int i = 0; i < freq[1]; i++) {
            one_cnt = (one_cnt * 2) % M;
        }

        val = (val * one_cnt) % M;
        return val;
    }
};