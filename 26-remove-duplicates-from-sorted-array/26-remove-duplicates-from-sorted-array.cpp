class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int front = 0;
        int curr = 0;
        int old_curr;
        while(curr<nums.size()){
            nums[front] = nums[curr];
            old_curr = curr;
            while(curr<nums.size()
                  && nums[curr]==nums[old_curr]) curr++;
            front++;
        }
        return front;
    }
};