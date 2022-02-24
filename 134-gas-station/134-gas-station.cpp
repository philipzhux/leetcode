/* 
   MAIN IDEA:
   =======================================
   this is based on the idea that if we sum from
   the start and it becomes negative,the sum of 
   the rest must be positive to have a solution. 
   So we start trying from there, and we always
   restart when the current sum goes below zero,
   as it basically indicates that the sum of all
   previous is negative, so the sum of all 
   follows shall be positive, then go on and on.
   If we have a solution, the res is current. 
   Therefore we use the total to check whether a
   solution if feasible.

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0,total = 0, res = -1,tmp;
        for(int i=0;i<gas.size();i++) {
            tmp = (gas[i]-cost[i]);
            total += tmp;
            current += tmp;
            if(current<0) {
                current = 0;
                res = i+1;
            }
        }
        if(total>=0) return res>0?res:0;
        return -1;
    }
};