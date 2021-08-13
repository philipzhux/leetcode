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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* tmp;
        if(k==1) return head;
        for(int i=0;i<k;i++){
            if(ptr==NULL) return head;
            ptr = ptr->next;
        }
        tmp = reverseEntiry(head,ptr);
        head->next = reverseKGroup(ptr,k);
        return tmp;
    }
    
    ListNode* reverseEntiry(ListNode* head,ListNode* tail) {
        ListNode* ptr = head;
        ListNode* pre = NULL;
        ListNode* suc = NULL;
        while(ptr!=tail){
            suc = ptr -> next;
            ptr -> next = pre;
            pre = ptr;
            ptr = suc;
        }
        return pre;
    }
};