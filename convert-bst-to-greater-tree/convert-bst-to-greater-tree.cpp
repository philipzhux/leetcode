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
    TreeNode* convertBST(TreeNode* root) {
        //traverse(root);
        int sum = 0;
        stack<TreeNode*> des;
        TreeNode* ptr = root;
        while(!des.empty()||ptr){
            while(ptr){
                des.push(ptr);
                ptr = ptr->right;
            }
            ptr = des.top();
            des.pop();
            sum+= ptr->val;
            ptr->val = sum;
            ptr = ptr->left;
        }
        return root;
    }
private:
    // int sum=0;
    // void traverse(TreeNode* root) {
    //     if(!root) return;
    //     traverse(root->right);
    //     sum += root->val;
    //     root->val = sum;
    //     traverse(root->left);
    //}
};