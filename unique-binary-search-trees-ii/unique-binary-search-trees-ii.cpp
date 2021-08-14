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
    vector<TreeNode*> generateTrees(int n) {
        return buildTrees(1,n);
    }
    
    vector<TreeNode*> buildTrees(int start, int end) {
        TreeNode* root;
        vector<TreeNode*> left_set,right_set,res;
        if(start>end){
            res.push_back(nullptr);
        }
        for(int i=start;i<=end;i++) {
            left_set = buildTrees(start,i-1);
            right_set = buildTrees(i+1,end);
            for(auto l_node:left_set){
                for(auto r_node:right_set){
                    root = new TreeNode(i);
                    root->left = l_node;
                    root->right = r_node;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};