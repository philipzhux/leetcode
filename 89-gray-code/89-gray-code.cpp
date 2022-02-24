class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0,1};
        int mask;
        if(n==1) return res;
        for(int i=1;i<n;i++){
            mask = 1<<i;
            auto old_size = res.size();
            for(int k=old_size-1; k>=0; --k) {
                res.push_back(res[k]|mask);
            }
        }
        return res;
    }
};