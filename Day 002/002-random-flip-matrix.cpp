// https://leetcode.com/problems/random-flip-matrix/



#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------- SOLUTION - 1 ----------------------------------------------------------------
class Solution {
public:
    int N, M, total;
    unordered_map<int, int> mpp;
    default_random_engine rand;

    // TC : O(1)
    // SC : O(M*N)
    Solution(int m, int n) : M(m), N(n), total(m*n), rand(random_device{}()) {};
    // TC : O(1)
    vector<int> flip() {
        uniform_int_distribution<int> dist(0, total - 1);
        int x = dist(rand);
        total--;

        // check if the random no. is in map
        auto it = mpp.find(x);
        int idx = (it != mpp.end()) ? it->second : x;

        it = mpp.find(total);
        mpp[x] = (it != mpp.end()) ? it->second : total;

        return {idx / N, idx % N};
    }
    // TC : O(1)
    void reset() {
        total = M*N;
        mpp.clear();
    }
};


// ----------------------------------------------- SOLUTION - 2 --------------------------------------------------------------

// TC : O(1)
// SC : O(1)
class Solution {
public:
    int M;
    int N;
    int i = 0, j = 0;
    Solution(int m, int n) {
        this -> M = m;
        this -> N = n;
    }
    
    vector<int> flip() {
        int I = i, J = j;

        if ((j + 1) < N) j ++;
        else if (i + 1 < M) {
            i ++;
            j = 0;
        }
        else {
            i = 0, j = 0;
        }
        return {I, J};
    }
    
    void reset() {
        
    }
};