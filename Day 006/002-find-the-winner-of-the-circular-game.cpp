// https://leetcode.com/problems/find-the-winner-of-the-circular-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int solve_queue(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            int cnt = k;
            while(cnt > 1) {
                int ele = q.front();
                q.pop();
                q.push(ele);
                cnt --;
            }
            q.pop();
        }

        return q.front();
    }

    // TC : O(N)
    // SC : O(N) -> Recursive depth
    int solve(vector<int>& arr, int k, int idx) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int removeIdx = (idx + k - 1) % n;
        arr.erase(begin(arr) + removeIdx);

        return solve(arr, k, removeIdx);
    }

    // TC : O(N)
    // SC : O(N) + O(N) = O(N)
    int solve_josephus(int n, int k) {
        vector<int> arr(n, 0);
        for (int i = 1; i <= n; i++) {
            arr[i - 1] = i;
        }

        return solve(arr, k, 0);
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    int solve_rec(int n, int k) {
        if (n == 1) return 0;
        return (solve_rec(n - 1, k) + k) % n;
    }
public:
    int findTheWinner(int n, int k) {
        // return solve_queue(n, k);

        // return solve_josephus(n, k);

        return solve_rec(n, k)+1;
    }
};