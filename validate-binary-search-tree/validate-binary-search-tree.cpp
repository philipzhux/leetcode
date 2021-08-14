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
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,nullptr,nullptr);
    }
    
    bool isValidBST(TreeNode* root, TreeNode *min, TreeNode *max) {
        if(!root) return true;
        if((max && root->val>=max->val) || (min && root->val<=min->val)) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};