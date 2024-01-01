// https://leetcode.com/problems/high-access-employees/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N)) -> Where N = No. of Access Time
    // SC : O(N)
    vector<string> solve_approach_1(vector<vector<string>>& access_times) {
        int n = access_times.size();
        
        sort(begin(access_times), end(access_times));

        unordered_map<string, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }

        vector<string> result;
        
        for (auto& it : mpp) {
            string employee    = it.first;
            vector<int>& times = it.second;

            for (int i = 0; i < times.size(); i++) {
                int cnt = 1;
                int j   = i + 1;

                while (j < times.size() && (times[j] - times[i] < 100)) {
                    cnt ++;
                    j ++;
                }

                if (cnt >= 3) {
                    result.push_back(employee);
                    break;
                }
            }
        }

        return result;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        return solve_approach_1(access_times);
    }
};