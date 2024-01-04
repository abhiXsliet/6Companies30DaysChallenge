// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/



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
    vector<int> solve_1(TreeNode* root, int& result) {
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0}; // max, min, sum
        }

        vector<int> left  = solve_1(root -> left , result);
        vector<int> right = solve_1(root -> right, result);

        // INVALID BST
        if (left[1] >= root -> val || right[0] <= root -> val) {
            return {INT_MIN, INT_MAX, 0};
        }

        int sum = left[2] + root -> val + right[2];

        result = max(sum, result);

        return {min(root -> val, left[0]), max(root -> val, right[1]), sum};
    }
    
    void solve_2(TreeNode* root, int& result, int& min_val, int& max_val, int& sum) {
        if (root == NULL) {
            min_val = INT_MAX;
            max_val = INT_MIN;
            sum     = 0;
            return;
        }

        int left_min, left_max, left_sum;
        solve_2(root -> left, result, left_min, left_max, left_sum);

        int right_min, right_max, right_sum;
        solve_2(root -> right, result, right_min, right_max, right_sum);

        // INVALID BST
        if (left_max >= root -> val || right_min <= root -> val) {
            min_val = INT_MIN;
            max_val = INT_MAX;
            sum     = 0;
            return;
        }

        sum = left_sum + root -> val + right_sum;
        result = max(result, sum);

        min_val = min(root -> val, left_min);
        max_val = max(root -> val, right_max);
    }

    int solve_approach_1(TreeNode* root) {
        int result = 0;

        solve_1(root, result);

        return result;
    }

    int solve_approach_2(TreeNode* root) {
        int result = 0;
        int min_val, max_val, sum;

        solve_2(root, result, min_val, max_val, sum);

        return result;
    }
public:
    int maxSumBST(TreeNode* root) {
        // return solve_approach_1(root);

        return solve_approach_2(root);    
    }
};