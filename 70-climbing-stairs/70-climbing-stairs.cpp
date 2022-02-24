class Solution {
public:
    int climbStairs(int n) {
        int prevv = 0;
        int prev = 1;
        int sum = 0;
        int tmp;
        for(int i=1;i<n;i++){
            tmp = prev;
            prev = prev+prevv;
            prevv = tmp;
        }
        return prev+prevv;
    }
};