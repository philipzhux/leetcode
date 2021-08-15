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
    int maxSumBST(TreeNode* root) {
        doMaxSum(root);
        return sum;
    }
private:
    enum index{
        IS_BST=0,
        SUM,
        MAX,
        MIN
    };
    int sum;
    int* doMaxSum(TreeNode* root) {
        if(!root) return new int[] {1,0,INT_MIN,INT_MAX};
        int* res = new int[4];
        int* right = doMaxSum(root->right);
        int* left = doMaxSum(root->left);
        if(!(res[IS_BST] = (right[IS_BST]&&left[IS_BST]&&root->val>left[MAX]&&root->val<right[MIN]))) 
            return res;
        res[IS_BST] = 1;
        res[SUM] = right[SUM]+left[SUM]+root->val;
        res[MAX] = max(right[MAX],root->val); res[MIN] = min(root->val,left[MIN]);
        sum = max(sum,res[SUM]);
        return res;
    }
    
    
};