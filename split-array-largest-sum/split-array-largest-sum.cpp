class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        /**
        m subarrays -> largest sum
        largest sum -> how many subarrays?
        larger the sum, smaller the array num;
        **/
        int right = findMaxSum(nums);
        int left = findMinSum(nums);
        int mid,res;
        while(left<=right) {
            mid = left + (right-left)/2;
            res = sumToArrayNum(nums,mid);
            /** array num too large, sum too small **/
            if(res>m) left = mid+1;
            else if(res<m) right = mid-1;
            else right = mid-1;
        }
        return left;
    }
    
    int sumToArrayNum(const vector<int>& nums, int max_sum) {
        int sum = 0;
        int count = 1;
        for(int i: nums) {
            if(sum+i>max_sum) {
                count++;
                sum=i;
                continue;
            }
            sum+=i;
        }
        return count;
    }
    
    int findMaxSum(const vector<int>& nums) {
        int sum = 0;
        for(int i: nums) sum+=i;
        return sum;
    }
    
    int findMinSum(const vector<int>& nums) {
        return *max_element(nums.begin(),nums.end());
    }
};