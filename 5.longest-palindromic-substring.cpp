/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

/* DP Table Filling takeaway:
 * Elements to make clear:
 * [Base Case]
 * DP[i][i] = true
 * [Transition Function]
 * DP[i][j] = DP[i+1][j-1] && s[i]==s[j] (j-i>3)
 * DP[i][j] = s[i]==s[j] (0<j-i<=3)
 * [Iteration Order]
 * Mental picture: the table
 * In this case the diagonal entries is the base
 * case, and propagate from there to outside
 * which in the context of problem is going from
 * small length to long length 
 */

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> DP(s.size(),
        vector<bool>(s.size()));
        int max_len = 1;
        int begin = 0;
        int j;
        /* DP iteration sequence: from short
        strings to long strings */
        for(int i=0;i<s.size();++i) {
            DP[i][i] = true;
        }
        for(int len=2;len<=s.size();len++){
            for(int i=0;i<s.size();i++){
                j = i+len-1;
                if(j>=s.size()) break;
                if (s[i]!=s[j]) DP[i][j] = false;
                else if(len<=3) DP[i][j] = true;
                else DP[i][j] = DP[i+1][j-1];
                if(DP[i][j] && len>max_len) {
                    max_len = len;
                    begin = i;
                }
            }
        }
        return s.substr(begin,max_len);
    }
};
// @lc code=end

