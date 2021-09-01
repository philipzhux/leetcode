class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoList cont;
        int t;
        vector<int> res;
        for(t=0;t<k-1;t++) cont.push(nums[t]);
        while(t<nums.size()){
            cont.push(nums[t]);
            res.push_back(cont.get_max());
            cont.pop_front(nums[t-k+1]);
            t++;
        }
        return res;
        
    }
class MonoList {
public:
    MonoList() {}
    void push(int t) {
        while(!data.empty() && data.back()<t) data.pop_back();
        data.push_back(t);
    }
    
    int get_max() {
        return data.front();
    }
    void pop_front(int t) {
        if(data.front()==t) data.pop_front();
    }
private:
    list<int> data;
    
};
};