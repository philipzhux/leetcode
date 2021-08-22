class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            if(s[start]!=s[end]) return helper(s.substr(start+1,end-start)) ||
                    helper(s.substr(start,end-start));
            start++;
            end--;
        }
        return true;

    }
    
    bool helper(string s) {
        string t =s;
        reverse(t.begin(),t.end());
        return s==t;
    }
    
};