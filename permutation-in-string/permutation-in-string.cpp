class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map <char,int> req, cont;
        int begin=0, end=0, fulfill=0, len=0, rlen=s1.size();
        for(char c: s1) req[c]++;
        char tmp;
        while(end<s2.size()){
            while(fulfill<req.size() && end<s2.size()) {
                end++;
                tmp = s2[end-1];
                if(req.count(tmp) && ++cont[tmp]==req[tmp]) fulfill++;
            }
            
            while(fulfill>=req.size()) {
                len = end-begin;
                if(len==rlen) return true;
                tmp = s2[begin];
                if(req.count(tmp) && --cont[tmp]<req[tmp]) fulfill--;
                begin++;
            }
        }
        return false;
    }
};