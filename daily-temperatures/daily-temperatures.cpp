class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> temp;
        for(int t=temperatures.size()-1;t>=0;t--){
            while(!temp.empty() && temperatures[temp.top()]<=temperatures[t]) {
                temp.pop();
            }
            res[t] = temp.empty()?0:(temp.top()-t);
            temp.push(t);
        }
        return res;
        }
};