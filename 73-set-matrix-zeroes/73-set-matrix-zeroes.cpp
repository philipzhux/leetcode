class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> z_rows, z_cols;
        int n = matrix.size();
        if(!n) return;
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                {
                    z_cols.insert(j);
                    z_rows.insert(i);
                }
            }
        }
        for(const auto &t: z_rows){
            for(int i=0;i<m; i++) matrix[t][i] = 0;
        }
        
        for(const auto &t: z_cols){
            for(int i=0;i<n; i++) matrix[i][t] = 0;
        }
    }
};
/* alternative: use first row and first column to hold whether that row/col is
to be zeroed out */