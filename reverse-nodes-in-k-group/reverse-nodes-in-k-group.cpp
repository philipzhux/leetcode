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
        for(int i=1;i<k;i++){
            if(ptr==NULL) return head;
            ptr = ptr->next;
            if(ptr==NULL) return head;
        }
        tmp = ptr -> next;
        ptr -> next = NULL;
        ptr = reverseEntiry(head);
        head -> next = reverseKGroup(tmp,k);
        return ptr;
    }
    
    ListNode* reverseEntiry(ListNode* head) {
        ListNode* ptr = head;
        ListNode* pre = NULL;
        ListNode* suc = NULL;
        while(ptr->next){
            suc = ptr -> next;
            ptr -> next = pre;
            pre = ptr;
            ptr = suc;
        }
        ptr->next = pre;
        return ptr;
    }
};