class Solution {
public:
    

    int search(vector<int>& nums, int target) {
        return meta_binary(nums,0,nums.size()-1,target);
    }
    
    int meta_binary(const vector<int>& nums, int left, int right, int target) {
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<nums[right]) {
            if(target>nums[mid] && target<=nums[right]) return binary(nums,mid+1,right,target);
            return meta_binary(nums,left,mid-1,target);
        }
        else { //nums[mid]>nums[right]
            if(target<nums[mid] && target>=nums[left]) return binary(nums,left,mid-1,target);
            return meta_binary(nums,mid+1,right,target);
        }
    }
    
    int binary(const vector<int>& nums, int left, int right, int target) {
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target) return binary(nums,mid+1,right,target);
        return binary(nums,left,mid-1,target);
    }
    
};