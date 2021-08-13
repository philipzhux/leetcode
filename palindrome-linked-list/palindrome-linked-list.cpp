/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        ListNode* left = head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!=NULL){
            slow = slow->next;
        }
        ListNode* ptr = reverse(slow);
        while(ptr) {
            if(ptr->val!=left->val) return false;
            ptr = ptr -> next;
            left = left -> next;
        }
        return true;
    }
    

    
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* suc;
        ListNode* ptr = head;
        while(ptr){
            suc = ptr->next;
            ptr -> next = pre;
            pre = ptr;
            ptr = suc;
        }
        return pre;
    }
};