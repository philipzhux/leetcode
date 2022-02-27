/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        std::reverse(s.begin(),s.end());
        size_t begin, end, it;
        bool initial = true;
        it = 0;
        while(it<s.size()){
            begin = it;
            while(it<s.size() && s[it]==' '){
                it++;
            }
            if(min(begin+1,s.size()-1)<it) {
                s.erase(min(begin+1,s.size()-1),it-min(begin+1,s.size()-1));
                begin++;
            }
            else begin = it;
            end = begin;
            while(end<s.size() && s[end]!=' ') end++;
            std::reverse(s.begin()+begin,s.begin()+end);
            it = end;
        }
        if(s[s.size()-1]==' ') s.erase(s.size()-1,1);
        if(s[0]==' ') s.erase(0,1);
        return s;
    }
};
// @lc code=end