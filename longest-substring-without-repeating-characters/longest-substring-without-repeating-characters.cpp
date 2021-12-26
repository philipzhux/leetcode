class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> buffer;
        int maxc = 0;
        int count = 0;
        int start = 0;
        int end = 0; // one past the end

        for(auto c: s){
            if(!buffer.count(c)){
                buffer.insert(c);
                count++;
                if(count>maxc) maxc = count;
            }
            else {
                while(s[start]!=c){
                    buffer.erase(s[start]);
                    count--;
                    start++;
                }
                start+=1;
            }
        }
        return maxc;
    }
};