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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
    }
    
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder, int inl,
                   int inr, int postl) {
        if(inl>inr) return NULL;
        int root_val = postorder[postl];
        int mid = std::find(inorder.begin()+inl,inorder.begin()+inr,root_val) - inorder.begin();
        return new TreeNode(root_val,build(inorder,postorder,inl,mid-1,postl-1-inr+mid),build(inorder,postorder,mid+1,inr,postl-1));
    }
};