// https://leetcode.com/problems/trim-a-binary-search-tree/



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
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    TreeNode* solve_1(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;

        if (root -> val < low) {
            return solve_1(root -> right, low, high);
        }

        if (root -> val > high) {
            return solve_1(root -> left, low, high);
        }

        root -> left  = solve_1(root -> left , low, high);
        root -> right = solve_1(root -> right, low, high);

        return root;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    TreeNode* solve_2(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;

        if (root -> val >= low && root -> val <= high) {
            root -> left  = solve_2(root -> left , low, high);
            root -> right = solve_2(root -> right, low, high);
            return root;
        }
        else if (root -> val < low) {
            return solve_2(root -> right, low, high);
        }
        else if (root -> val > high) {
            return solve_2(root -> left, low, high);
        }
        
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // return solve_1(root, low, high);

        return solve_2(root, low, high);
    }
};