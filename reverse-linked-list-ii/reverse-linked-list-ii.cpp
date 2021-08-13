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
    ListNode* successor = NULL;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1) return reverseStart(head,right);
        ListNode* last = reverseBetween(head->next,left-1,right-1);
        head->next = last;
        return head;
        
    }
    
    ListNode* reverseStart(ListNode* head, int t) {
        if(t==1){
            successor = head->next;
            return head;
        }
        ListNode* last = reverseStart(head->next,t-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
};