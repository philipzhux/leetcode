/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums,nums.size()-k+1,0,nums.size()-1);
    }

    int quickFind(vector<int>& nums, int k,int begin,int end) {
        if(begin==end) return nums[begin];
        int p_index = partition(nums,begin,end);
        int current_k = p_index-begin+1;
        if(current_k == k) return nums[p_index];
        if(current_k > k) return quickFind(nums,k,begin,p_index-1);
        return quickFind(nums,k-current_k,p_index+1,end);
    }

    int partition(vector<int>& nums,int begin,int end) {
        int pivot = nums[end];
        int pivot_index = begin;
        for(int i = begin; i<end; i++){
            if(nums[i]<=pivot) {
                exchange(nums[i],nums[pivot_index]);
                pivot_index++;
            }
        }
        exchange(nums[pivot_index],nums[end]);
        return pivot_index;
    }
    void exchange(int &a, int &b)
    {
        int tmpInt = a;
        a = b;
        b = tmpInt;
        return;
    }


};