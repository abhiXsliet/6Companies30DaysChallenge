// https://leetcode.com/problems/erect-the-fence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getEquationVal(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
        int x1 = a.first;
        int x2 = b.first;
        int x3 = c.first;

        int y1 = a.second;
        int y2 = b.second;
        int y3 = c.second;

        return (y3 - y2)*(x2 - x1) - (y2 - y1)*(x3 - x2);
    }

    // TC : O(N*log(N))
    // SC : O(N)
    vector<vector<int>> solve_approach_1(vector<vector<int>>& trees) {
        sort(begin(trees), end(trees));

        deque<pair<int, int>> lowerConvexHull, upperConvexHull;

        for (auto& coordinates : trees) {

            int lowerSize = lowerConvexHull.size();
            int upperSize = upperConvexHull.size();

            while (lowerSize >= 2 &&
                   getEquationVal( lowerConvexHull[lowerSize - 2], 
                                   lowerConvexHull[lowerSize - 1], 
                                   {coordinates[0], coordinates[1]} ) < 0) {
                                      
                lowerSize --;
                lowerConvexHull.pop_back();
            }

            while (upperSize >= 2 &&
                   getEquationVal( upperConvexHull[upperSize - 2], 
                                   upperConvexHull[upperSize - 1], 
                                   {coordinates[0], coordinates[1]} ) > 0) {
                                      
                upperSize --;
                upperConvexHull.pop_back();
            }

            lowerConvexHull.push_back({coordinates[0], coordinates[1]});
            upperConvexHull.push_back({coordinates[0], coordinates[1]});
        }

        set<pair<int, int>> st;

        for (auto& coordinate : lowerConvexHull) {
            st.insert(coordinate);
        }

        for (auto& coordinate : upperConvexHull) {
            st.insert(coordinate);
        }

        vector<vector<int>> result;
        for (auto& coordinate : st) {
            result.push_back({coordinate.first, coordinate.second});
        }

        return result;
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        return solve_approach_1(trees);
    }
};