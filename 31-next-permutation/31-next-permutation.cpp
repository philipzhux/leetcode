class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        auto left = nums.end()-2;
        while(left>=nums.begin()){
            auto right = nums.end()-1;
            while(right>left && *left>=*right){
                right--;
            }
            if(*left<*right) {
                auto temp = *left;
                *left = *right;
                *right = temp;
                sort(left+1,nums.end());
                return;
            }
            left--;
        }
        sort(nums.begin(),nums.end());
        return;
    }
};