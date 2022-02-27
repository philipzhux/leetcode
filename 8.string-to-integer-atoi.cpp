/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        bool pos = true;
        long i = 0;
        for(const auto & c: s){
            if(c==' ' && !sign) continue;
            if(c=='-' && !sign) {
                pos = false;
                sign = true;
                continue;
            }
            if(c=='+' && !sign) {
                sign = true;
                continue;
            }
            if(c>='0' && c<='9'){
                sign = true;
                i = i*10+c-'0';
                if (i>INT_MAX)
                {
                    return pos?INT_MAX:INT_MIN;
                }
                
                continue;
            }
            break;
        }
        if(!pos) i = ~i+1;
        return i;
    }
};
// @lc code=end

