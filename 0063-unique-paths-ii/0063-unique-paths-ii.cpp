int gridseqn(vector<vector<int>>& obstacleGrid,int maxrow,int maxcol,vector<vector<int>>& dp,int row,int col){
    if(row==maxrow && col==maxcol){
        if(obstacleGrid[row][col]!=1) return 1;
        else return 0;
    }
    if(row>maxrow || col>maxcol){
        return 0;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    if(obstacleGrid[row][col]!=1){
        int left = gridseqn(obstacleGrid,maxrow,maxcol,dp,row+1,col);
        int right = gridseqn(obstacleGrid,maxrow,maxcol,dp,row,col+1);
        return dp[row][col]=(left+right);
    }
    
    dp[row][col]=0;
    return 0;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return(gridseqn(obstacleGrid,m-1,n-1,dp,0,0));
    }
};