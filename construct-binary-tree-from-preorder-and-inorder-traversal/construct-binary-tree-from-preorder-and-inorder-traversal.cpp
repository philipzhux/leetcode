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
#include <algorithm>
class Solution {
public:
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    int prel,int inl, int inr) {
        if(inl>inr) return NULL;
        int root_val = preorder[prel];
        int in_mid = find(inorder.begin()+inl,inorder.begin()+inr,root_val)-inorder.begin();
        return new TreeNode(root_val,build(preorder,inorder,prel+1,inl,in_mid-1),build(preorder,inorder,in_mid-inl+prel+1,in_mid+1,inr));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return build(preorder,inorder,0,0,inorder.size()-1);    
    }
    
};