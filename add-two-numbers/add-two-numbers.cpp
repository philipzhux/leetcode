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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = l1;
        ListNode* curr_alt = l2;
        ListNode* curr_active;
        bool flag_l1 = true;
        bool flag_l2 = true;
        int carry = 0;
        int res = 0;
        while(curr || curr_alt){
            if(!curr) flag_l1 = false;
            if(!curr_alt) flag_l2 = false;
            if(flag_l1 && flag_l2){
                curr_active = curr;
                res = (curr->val + curr_alt->val + carry)%10;
                carry = (curr->val + curr_alt->val + carry)/10;
                curr->val = res;
                curr_alt->val = res;
                curr = curr->next;
                curr_alt = curr_alt->next;
            }
            else{
                curr_active = flag_l1?curr:curr_alt;
                res = (curr_active->val + carry)%10;
                carry = (curr_active->val + carry)/10;
                curr_active->val = res;
                if(flag_l1) curr = curr->next;
                else curr_alt = curr_alt -> next;
            }
        }
        if(carry) curr_active->next = new ListNode(carry); 
        return flag_l1?l1:l2;
    }
};