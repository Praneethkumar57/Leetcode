int seqn(vector<vector<int>>& grid,int maxrow,int maxcol,vector<vector<int>>& dp,int row,int col){
    if(row==maxrow && col==maxcol){
        return(grid[row][col]);
    }
    if(row>maxrow || col>maxcol){
        return INT_MAX;
    }
    if(dp[row][col]!=-1){
        return(dp[row][col]);
    }

    int left = seqn(grid,maxrow,maxcol,dp,row+1,col);
    int right = seqn(grid,maxrow,maxcol,dp,row,col+1);
    int mini = min(left,right);
    return(dp[row][col] = grid[row][col]+mini);
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        return seqn(grid,row-1,col-1,dp,0,0);
    }
};