class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){return a[1]<b[1];});
        int shot = points[0][1];
        int count=1;
        for(auto c: points) {
            if(c[0]<=shot) continue;
            shot = c[1];
            count++;
        }
    return count;
    }
};