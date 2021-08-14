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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int rank=0;
        traverse(root,rank,res,k);
        return res;
    }
    
    void traverse(TreeNode* root, int& rank, int& res, const int& k) {
        if(!root||rank>k) return;
        traverse(root->left,rank,res,k);
        if(++rank==k) {
            res = root->val;
            return;
        }
        traverse(root->right,rank,res,k);
    }
};