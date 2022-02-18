class Solution {
public:
    vector<int> DP;
    int numDecodings(string s) {
        DP.resize(s.size());
        for(auto& u: DP) u = -1;
        helper(s.size()-1,s);
        for(auto& u: DP) cout<<u<<endl;
        return DP[s.size()-1];
    }
    
    int helper(int i,const string & s) {
        int res = 0;
        int first_digt;
        int second_digt;
        if(DP[i]>=0) return DP[i];
        if(i==1) {
            first_digt = s[1]-'0';
            second_digt = s[0]-'0';
            if(first_digt) res+=helper(i-1,s);
            if(second_digt && (second_digt*10+first_digt)<=26) res+= 1;
            DP[1] = res;
            return res;
        }
        if(i==0) {
            res = (s[i]>'0')?1:0;
            DP[0] = res;
            return res;
        }
        first_digt = s[i]-'0';
        second_digt = s[i-1]-'0';
        if(first_digt) res+=helper(i-1,s);
        if(second_digt && (second_digt*10+first_digt)<=26) res+= helper(i-2,s);
        DP[i] = res;
        return res;
    }
};