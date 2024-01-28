// https://leetcode.com/problems/maximum-product-after-k-increments/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    // TC : O(N*log(N))
    // SC : O(N)
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) pq.push(num);

        while (!pq.empty() && k > 0) {
            int topN = pq.top();
            pq.pop();

            topN += 1;
            k    -= 1;
            
            pq.push(topN);
        }

        long long result = 1;
        while (!pq.empty()) {
            result = (result * pq.top()) % MOD;
            pq.pop();
        }
        return (int)result;
    }
};