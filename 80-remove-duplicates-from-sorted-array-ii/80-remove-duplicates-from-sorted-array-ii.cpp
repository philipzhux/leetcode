class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        if(k<=2) return k;
        int count = 2;
        for(int i=2;i<k;i++){
            if(nums[i]!=nums[count-2]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};