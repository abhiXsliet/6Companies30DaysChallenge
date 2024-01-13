// https://leetcode.com/problems/friends-of-appropriate-ages/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(vector<int>& ages, int n) {
        int cntRequest = 0;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x != y && !(ages[y] <= 0.5 * ages[x] + 7 
                || ages[y] > ages[x] || (ages[y] > 100 && ages[x] < 100))) {

                    cntRequest++;
                }
            }
        }

        return cntRequest;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_better(vector<int>& ages, int n) {
        sort(ages.begin(), ages.end());
        
        int cntRequest = 0;
        int left = 0, right = 0;

        // for each age x, we find the range of ages y 
        // that can receive a friend request from x by moving the left & right pointers
        for (int x = 0; x < n; x++) {
            // No one can send friend requests to people under 15
            if (ages[x] < 15) {
                continue; 
            }
            // Find the left bound where age[y] > 0.5 * age[x] + 7
            while (ages[left] <= 0.5 * ages[x] + 7) {
                left++;
            }
            // Find the right bound where age[y] <= age[x]
            while (right + 1 < n && ages[right + 1] <= ages[x]) {
                right++;
            }
            cntRequest += right - left;
        }

        return cntRequest;
    }

    bool request (int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_optimal(vector<int>& ages, int n) {
        unordered_map<int, int> freq;

        for (int age : ages) {
            freq[age]++;
        }

        int cntRequest = 0;
        for (auto& a : freq) {
            for (auto& b : freq) {
                if (request(a.first, b.first)) {

                    cntRequest += a.second * (b.second - (a.first == b.first ? 1 : 0));
                }
            }
        }
        return cntRequest;
    }
public:
    int numFriendRequests(vector<int>& ages) {
        // return solve_brute(ages, ages.size());

        // return solve_better(ages, ages.size());

        return solve_optimal(ages, ages.size());
    }
};