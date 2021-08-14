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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        find_id(root,res);
        return res;
    }
    
private:
    unordered_map<unsigned long, int> record;
    unordered_map<int,int> id_time;
    int find_id(TreeNode* root,vector<TreeNode*>& res){
        int left_id = (root->left)?find_id(root->left,res):0;
        int right_id = (root->right)?find_id(root->right,res):0;
        unsigned long key = (unsigned long)(root->val)<<32|(left_id<<16)|(right_id);
        if(!record.count(key)){
            int id = record.size()+1;
            record[key] = id;
            id_time[id]=1;
            return id;
        }
        int id = record[key];
        id_time[id]++;
        if(id_time[id]==2) res.push_back(root);
        return id;
    }
};