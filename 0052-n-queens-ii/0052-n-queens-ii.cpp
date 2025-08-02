bool issafe(vector<string>& board,int row, int col, int n){
    int rowdup = row;
    int coldup = col;
    
    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row--;
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
        col--;
        row++;
    }

    return true;
}

int nqueen(int n,vector<string>& board,int row,int col){
    if(col==n){
        return 1;
    }

    int cnt=0;
    for(int row=0;row<n;row++){
        if(issafe(board,row,col,n)==true){
            board[row][col]='Q';
            cnt = cnt + nqueen(n,board,row,col+1);
            board[row][col]='.';
        }
    }
    return cnt;
}

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        return(nqueen(n,board,0,0));
    }
};