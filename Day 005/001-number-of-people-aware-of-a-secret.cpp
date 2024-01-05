// https://leetcode.com/problems/number-of-people-aware-of-a-secret/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[1001];
    #define M 1000000007

    // TC : O(N^(forget - delay + 1)) -> Exponential (TLE)
    // SC : O(N) -> Max. Recursive Depth
    int solve_rec(int n, int delay, int forget, int day) {
        if (day > n) {
            return 0;
        } 
        
        int ans = 1;
        for (int spreader = day+delay; spreader <= min(n, day+forget); spreader++) {
            if (spreader == day + forget) {
                ans -= 1;
                break;
            }
            ans = (ans + solve_rec(n, delay, forget, spreader)); 
        }
        return ans;
    }

    // TC : O(N * (forget - delay + 1)) ~= O(N)
    // SC : O(N)
    int solve_mem(int n, int delay, int forget, int day) {
        if (day > n) {
            return 0;
        } 

        if (t[day] != -1) 
            return t[day];
        
        int ans = 1;
        for (int spreader = day+delay; spreader <= min(n, day+forget); spreader++) {
            if (spreader == day + forget) {
                ans -= 1;
                break;
            }
            ans = (ans % M+ solve_mem(n, delay, forget, spreader) % M) % M; 
        }
        return t[day] = ans;
    }

    // TC : O(N * (forget - delay + 1)) ~= O(N)
    // SC : O(N)
    int solve_tab(int n, int delay, int forget) {
        vector<int> dp(n+forget+1, 0);

        // Day-1: only single persion knows the secret
        dp[1] = 1;

        for (int day = 1; day <= n; day++) {
            for (int share_sec = day + delay; share_sec < day + forget; share_sec++) {
                dp[share_sec] = (dp[share_sec] + dp[day]) % M;
            }
        }

        int ans = 0;
        for (int i = max(1, n-forget+1); i <= n; i++) {
            ans = (ans + dp[i]) % M;
        }
        return ans;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // return solve_rec(n, delay, forget, 1);

        // memset(t, -1, sizeof(t));
        // return solve_mem(n, delay, forget, 1);

        return solve_tab(n, delay, forget);
    }
};