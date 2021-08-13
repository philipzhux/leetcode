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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    
    TreeNode* build(const vector<int>& nums,int left,int right) {
        int max = INT_MIN;
        int index;
        for(int i=left;i<=right;i++){
            if(nums[i]>max) {
                max = nums[i];
                index = i;
            }
        }
        if(left>right) return NULL;
        if(left==right) return (new TreeNode(nums[left]));
        TreeNode* root = new TreeNode(max,build(nums,left,index-1),build(nums,index+1,right));
        return root;
    }
};