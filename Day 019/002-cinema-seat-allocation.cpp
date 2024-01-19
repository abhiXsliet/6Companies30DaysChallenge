// https://leetcode.com/problems/cinema-seat-allocation/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N) -> TLE
    // SC : O(N) -> MLE Where N = Rows Of Seats
    int solve_brute(int n, vector<vector<int>>& reservedSeats) {
        int cntGroup = 0;

        unordered_map<int, unordered_set<int>> mpp;
        for (auto& reserveSeat : reservedSeats) {
            mpp[reserveSeat[0]].insert(reserveSeat[1]);
        }

        int row = 1;
        while (row <= n) {
            bool case1 = true, case2 = true, case3 = true, case4 = true;
            for (int seat = 2; seat <= 9; ++seat) {
                if (mpp[row].count(seat)) {
                    if (seat >= 2 && seat <= 9) case1 = false;
                    if (seat >= 2 && seat <= 5) case2 = false;
                    if (seat >= 6 && seat <= 9) case3 = false;
                    if (seat >= 4 && seat <= 7) case4 = false;
                }
            }
            if (case1) cntGroup += 2;
            else if (case2 || case3 || case4) cntGroup += 1;
            row++;
        }
        return cntGroup;
    }

    // TC : O(M) 
    // SC : O(M) Where M = reservedSeats.size() ~= 10^4
    int solve_better(int n, vector<vector<int>>& reservedSeats) {
        int cntGroup = 0;

        unordered_map<int, unordered_set<int>> mpp;
        for (auto& reserveSeat : reservedSeats) {
            mpp[reserveSeat[0]].insert(reserveSeat[1]);
        }

        // Incase of no reservation for a particular row, then maximum 2-group of family can be accommodated
        cntGroup += (n - mpp.size()) * 2;

        for (auto& row : mpp) {
            bool case1 = true, case2 = true, case3 = true, case4 = true;
            for (int seat = 2; seat <= 9; ++seat) {
                if (row.second.count(seat)) {
                    if (seat >= 2 && seat <= 9) case1 = false;
                    if (seat >= 2 && seat <= 5) case2 = false;
                    if (seat >= 6 && seat <= 9) case3 = false;
                    if (seat >= 4 && seat <= 7) case4 = false;
                }
            }
            if (case1) cntGroup += 2;
            else if (case2 || case3 || case4) cntGroup += 1;
        }
        return cntGroup;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // return solve_brute(n, reservedSeats);

        return solve_better(n, reservedSeats);
    }
};