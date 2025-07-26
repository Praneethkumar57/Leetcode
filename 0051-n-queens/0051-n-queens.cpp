bool issafe(vector<string>& board,int row, int col,int n){
    int rowdup = row;
    int coldup = col;
    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row = rowdup;
    col = coldup;
    
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row = rowdup;
    col = coldup;

    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}

void nqueens(int col,vector<string>& board,int n,vector<vector<string>>& res){
    if(col == n){
        res.push_back(board);
        return;
    }

    for(int row =0;row<n;row++){
        if(issafe(board,row,col,n)){
            board[row][col]='Q';
            nqueens(col+1,board,n,res);
            board[row][col]='.';
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        nqueens(0,board,n,ans);
        return ans;
    }
};