class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1,-1};
        pair<int,int> ress = helper(nums,target,0,nums.size()-1);
        vector<int> res = {ress.first,ress.second};
        return res;
    }
    
    pair<int,int> helper(const vector<int>& nums, const int& target,int start,int end) {
        int mid = (start+end)/2;
        if(start==end) {
            if(nums[mid]==target) return make_pair(mid,mid);
            return make_pair(-1,-1);
        }
        if(start>end) return make_pair(-1,-1);
        if(nums[mid]<target) return helper(nums,target,mid+1,end);
        if(nums[mid]>target) return helper(nums,target,start,mid-1);
        int front = helper(nums,target,start,mid-1).first;
        int latter = helper(nums,target,mid+1,end).second;
        if(front==-1) front = mid;
        if(latter==-1) latter = mid;
        return make_pair(front,latter);
    }
};