/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
    static bool comp(ListNode* item1, ListNode* item2) {
        return item1->val>item2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *top,*tail,*head;
        priority_queue<ListNode*,vector<ListNode*>,decltype(&comp)> heap(comp);
        for(ListNode* ptr: lists)
            if(ptr) heap.push(ptr);
        if(heap.empty()) return NULL;
        top = heap.top();
        heap.pop();
        tail = top;
        head = tail;
        if(!top) return NULL;
        if(top->next) heap.push(top->next);
        while(!heap.empty()){
            top = heap.top();
            heap.pop();
            tail->next = top;
            tail = top;
            if(top && top->next) heap.push(top->next);
        }
        return head;
    }
};
// @lc code=end

