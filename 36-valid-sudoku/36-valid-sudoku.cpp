class Solution {
public:
    const char & getSub(const vector<vector<char>>& board,
                        int square_num,int square_row, int square_col) {
        int _row = square_num/3*3+square_row;
        int _col = square_num%3*3+square_col;
        return board[_row][_col];
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> used (9);
        for(int i=0; i<9; i++) {
            fill(used.begin(),used.end(),false);
            for(int j=0;j<9;j++) {
                if(!check(used,board[i][j])) {
                    //cout<<"row false at ("<<i<<","<<j<<")"<<endl;
                    return false;
                }
            }
            fill(used.begin(),used.end(),false);
            for(int j=0;j<9;j++) {
                if(!check(used,board[j][i]))  {
                    //cout<<"col false at ("<<i<<","<<j<<")"<<endl;
                    return false;
                }
            }
            fill(used.begin(),used.end(),false);
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    if(!check(used,getSub(board,i,j,k)))  {
                    //cout<<"sub false at ("<<i<<","<<j<<","<<k<<")"<<endl;
                    return false;
                }
                }
            }
        }
        return true;
    }

    bool check(vector<bool> &used, const char & c){
        if(c=='.') return true;
        if(used[c-'1']) return false;
        return (used[c-'1'] = true);
    }
};