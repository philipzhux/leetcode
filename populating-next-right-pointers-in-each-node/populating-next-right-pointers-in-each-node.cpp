/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL||root->left==NULL) return root;
        interconnect(root->left,root->right);
        return root;
    }
    
    void interconnect(Node* left, Node* right) {
        if(left) left->next = right;
        if(left) interconnect(left->left,left->right);
        if(right) interconnect(right->left,right->right);
        if(left && right) interconnect(left->right,right->left);
    }
};