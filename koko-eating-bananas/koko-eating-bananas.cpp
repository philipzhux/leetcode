class Solution {
public:
    vector<int> *ptr;
    int minEatingSpeed(vector<int>& piles, int h) {
        ptr = &piles;
        int right = getMaxSpeed(h);
        int left = 1;
        int mid;
        while(right>=left) {
            mid = right+ (left-right)/2;
            if(takesTime(mid)<h) right = mid-1;
            else if(takesTime(mid)>h) left = mid+1; 
            //speed too slow, select righter part
            else right=mid-1;
        }
        return left;
    }
    
    int takesTime(int speed) {
        int res =0;
        for(auto t: *ptr) res += ceil(double(t)/double(speed));
        return res;
    }
    int getMaxSpeed(int h) {
        return *max_element(ptr->begin(),ptr->end());
    }
};