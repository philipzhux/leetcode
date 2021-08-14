class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(0,graph,path);
        return res;
    }
    
private:
    vector<vector<int>> res;
    void traverse(const int& curr, const vector<vector<int>>& graph,vector<int>& path) {
        path.push_back(curr);
        if(curr==graph.size()-1) res.push_back(path);
        for(auto next: graph[curr]) {
            traverse(next,graph,path);
        }
        path.pop_back();
    }
};