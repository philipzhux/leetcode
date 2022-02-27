/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<char> open = {'(','[','{'};
    vector<char> close = {')',']','}'};
    bool isValid(string s) {
        stack<char> sta;
        for(const auto &c: s){
            if(find(open.begin(),open.end(),c)!=open.end()) {
                sta.push(c);
                continue;
            }
            if(find(close.begin(),close.end(),c)!=close.end()) {
                char t = *(open.begin()+(find(close.begin(),close.end(),c)-close.begin()));
                if(sta.empty()) return false;
                if(sta.top()!=t) {
                    cout<<sta.top()<<t<<endl;
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};
// @lc code=end

