/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        if(!p) return q;
        if(!q) return p;
        TreeNode* right_lcs = lowestCommonAncestor(root->right,p,q);
        TreeNode* left_lcs = lowestCommonAncestor(root->left,p,q);
        if(right_lcs && left_lcs) return root;
        if(right_lcs && !left_lcs) return right_lcs;
        if(left_lcs && !right_lcs) return left_lcs;
        return NULL;
    }
};
// @lc code=end

