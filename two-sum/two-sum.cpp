class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_map;
        for(int i=0;i<nums.size();i++){
            hash_map[nums[i]] = i;
            nums[i] = target-nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(hash_map.count(nums[i]) && i!=hash_map[nums[i]]){
                return {i,hash_map[nums[i]]};
            }
        }
        return {};
    }
};