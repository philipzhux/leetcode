class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> required,contained;
        int begin=0, end=0, fulfilled =0, mlen=s.size()+1;
        int res_begin;
        for(char c: t) required[c]+=1;
        while(end<s.size()){ //note that end is not included
            while(fulfilled<required.size() && end<s.size()){
                end++;
                //printf("end=%d\n",end);
                if(required.count(s[end-1]) &&
                   ++contained[s[end-1]]==required[s[end-1]]) fulfilled++;
            }
            while(fulfilled>=required.size()) {
                if(end-begin<mlen) {
                    mlen = end-begin;
                    res_begin = begin;
                }
                if(required.count(s[begin]) &&
                   (--contained[s[begin]])<required[s[begin]]) fulfilled--;
                begin++;
                //printf("begin=%d\n",begin);
            }
                
        }
        
        return mlen==s.size()+1?"":s.substr(res_begin,mlen);
    }
};