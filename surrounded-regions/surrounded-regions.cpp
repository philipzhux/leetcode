class Solution {
private:
    int rowl;
    int coll;
public:
    void solve(vector<vector<char>>& board) {
        rowl = board.size()-1;
        if(!rowl) return;
        coll = board[0].size()-1;
        for(int i=0;i<=coll;i++) {
            markSurroundings(board,0,i);
            markSurroundings(board,rowl,i);
        }
        for(int i=0;i<=rowl;i++) {
            markSurroundings(board,i,0);
            markSurroundings(board,i,coll);
        }
        for(auto& a: board) for(auto& b: a) if(b=='O') b='X';
        for(auto& a: board) for(auto& b: a) if(b=='#') b='O';
    }
    
    void markSurroundings(vector<vector<char>>& board, const int& row, const int& col) {
        if(board[row][col]=='O') {
            board[row][col] = '#';
            markSurroundings(board,min(row+1,rowl),col);
            markSurroundings(board,max(row-1,0),col);
            markSurroundings(board,row,min(col+1,coll));
            markSurroundings(board,row,max(col-1,0));
        }
    }
};