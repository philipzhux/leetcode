/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
class Solution {
public:
    string validIPAddress(string queryIP) {
        bool ipv4 = (find(queryIP.begin(),queryIP.end(),'.') !=queryIP.end());
        bool ipv6 = (find(queryIP.begin(),queryIP.end(),':') !=queryIP.end());
        bool begin = true;
        if(ipv4==ipv6) return "Neither";
        if(ipv4) {
            for (const auto & c: queryIP)
            {
                /* code */
            }
            
        }
    }
};
// @lc code=end

