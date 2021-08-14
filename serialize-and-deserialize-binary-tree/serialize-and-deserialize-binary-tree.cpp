/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    enum STATUS{
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    
    void serialize(TreeNode* root, ostringstream& out) {
        char status=0;
        if(!root) {
            out.write(&status,sizeof(char));
            return;
        }
        status = (root->right!=NULL)<<2|(root->left!=NULL)<<1|1;
        out.write(&status,sizeof(char));
        out.write(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
        if(root->left) serialize(root->left,out);
        if(root->right) serialize(root->right,out);
    }
    
    TreeNode* deserialize(istringstream& in) {
        char status;
        in.read(&status,sizeof(char));
        if(!(status&ROOT)) return NULL;
        TreeNode* res = new TreeNode(0);
        in.read(reinterpret_cast<char*>(&(res->val)),sizeof(res->val));
        res->left = (status & LEFT)?deserialize(in):NULL;
        res->right = (status & RIGHT)?deserialize(in):NULL;
        return res;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));