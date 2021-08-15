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
    int countNodes(TreeNode* root) {
        int hl=0;
        int hr=0;
        for(TreeNode* ptr=root;ptr!=NULL;ptr=ptr->left) hl++;
        for(TreeNode* ptr=root;ptr!=NULL;ptr=ptr->right) hr++;
        if(hl==hr) return pow(2,hl)-1;
        return countNodes(root->left) + countNodes(root->right) +1;
    }
};