#include <cstdlib>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==3) return (nums[0]+nums[1]+nums[2]);
        sort(nums.begin(),nums.end());
        auto n_end = nums.end();
        vector<int>::iterator j,k;
        int temp,res;
        int min_d = INT_MAX;
        for(auto i = nums.begin();i!=n_end-2;i++) {
            j = i+1;
            k = n_end-1;
            while(j<k) {
                temp = (*i+*j+*k);
                if(abs(temp-target)<min_d) {
                    min_d = abs(temp-target);
                    res = temp;
                }
                if(temp<target){
                    j++;
                    while(*j==*(j-1) && j<k) j++;
                }
                else if(temp>target) {
                    k--;
                    while(*k==*(k+1) && j<k) k--;
                }
                else return target;
            }
        }
        return res;
    }
};