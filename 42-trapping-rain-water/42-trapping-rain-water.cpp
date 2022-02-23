class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        int max = 0;
        int sum = 0;
        left_max[0] = 0;
        right_max[height.size()-1] = 0;
        for(int i=1;i<height.size();i++) {
            max = std::max(max,height[i-1]);
            left_max[i] = max;
        }
        max = 0;
        for(int i=height.size()-2;i>=0;i--) {
            max = std::max(max,height[i+1]);
            right_max[i] = max;
        }
        for(int i=0;i<height.size();i++) {
            sum+= std::max(min(right_max[i],left_max[i])-height[i],0);
        }
        return sum;
    }
};