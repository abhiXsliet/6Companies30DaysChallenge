// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // TC : O(N), Where 'N' is the number of nodes in the tree
    // SC : O(N)
    vector<int> solve(TreeNode* root, int dist, int& ans) {
        if (!root) return {0};

        if (root -> left == NULL && root -> right == NULL)
            return {1};

        auto left  = solve(root -> left , dist, ans);
        auto right = solve(root -> right, dist, ans);

        for (auto a : left) {
            for (auto b : right) {
                if ((a && b) && a + b <= dist) {
                    ans ++;
                }
            }
        }

        // create the vector for returning to its parent
        vector<int> store;
        for (auto a : left)  {
            if (a && a + 1 < dist) 
                store.push_back(a + 1);
        }

        for (auto b : right)  {
            if (b && b + 1 < dist) 
                store.push_back(b + 1);
        }
        return store;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};