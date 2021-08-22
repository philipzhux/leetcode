class Solution {
public:
    bool judgeSquareSum(int c) {
        bool res = false;
        int mid = sqrt(c/2);
        for(int i = 0;i<=mid;i++){
            if(isSqrt(c-pow(i,2))) return true;
        }
        return false;
    }
    
    bool isSqrt(int c) {
        return pow(int(sqrt(c)),2)==c;
    }
};