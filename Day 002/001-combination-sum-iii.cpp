// https://leetcode.com/problems/combination-sum-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^n)
    // SC : O(k) -> Recursive Depth
    void solve_brute(int k, int n, int idx, vector<vector<int>>& result, vector<int>& store, vector<int>& candidates) {
        if (idx == candidates.size()) {
            if (k == 0 && n == 0)
                result.push_back(store);
            return;
        }

        if (idx < n) {
            store.push_back(candidates[idx]);
            solve_brute(k-1, n-candidates[idx], idx+1, result, store, candidates);
            store.pop_back();
        }
        solve_brute(k, n, idx+1, result, store, candidates);
        return;
    }

    // TC : O(9^k)
    // SC : O(k) -> Recursive Depth
    void solve_better(int k, int n, int idx, vector<vector<int>>& result, vector<int>& store, vector<int>& candidates) {
        if (k < 0 || n < 0) return;
        if (k == 0 && n == 0) {
            result.push_back(store);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            store.push_back(candidates[i]);
            solve_better(k-1, n-candidates[i], i+1, result, store, candidates);
            store.pop_back();
        }
    }

    // TC : O(9^k)
    // SC : O(k) -> Recursive Depth
    void solve_optimal(int k, int n, vector<vector<int>>& result, vector<int>& store, int candidate) {
        if (k < 0 || n < 0) return;  // stop recursion if k or n are negative
        if (k == 0 && n == 0) {
            result.push_back(store);
            return;
        }
        if (candidate > 9) return;  // stop recursion if the candidate > 9
        
        store.push_back(candidate);
        solve_optimal(k-1, n-candidate, result, store, candidate+1); 
        store.pop_back();
        solve_optimal(k, n, result, store, candidate+1);
    }

    vector<vector<int>> solve_approach_1(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> result;
        vector<int> store;
        
        solve_brute(k, n, 0, result, store, candidates);
        return result;
    }

    vector<vector<int>> solve_approach_2(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> result;
        vector<int> store;
        
        solve_better(k, n, 0, result, store, candidates);
        return result;
    }

    vector<vector<int>> solve_approach_3(int k, int n) {
        vector<vector<int>> result;
        vector<int> store;
        int candidate = 1;

        solve_optimal(k, n, result, store, candidate);
        return result;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // return solve_approach_1(k, n);

        // return solve_approach_2(k, n);

        return solve_approach_3(k, n);
    }
};