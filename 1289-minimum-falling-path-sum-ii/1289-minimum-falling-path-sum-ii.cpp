int seqn(vector<vector<int>>& grid,int n,int row,int col,vector<vector<int>>& dp){
    if(row == n-1){
        int mini = 1e9;
        for(int i=0;i<n;i++){
            if(i!=col){
                mini = min(mini,grid[row][i]);
            }
        }
        return(mini);
    }
    if(dp[row][col]!=1e9){
        return dp[row][col];
    }

    int mini = 1e9;
    for(int i=0;i<n;i++){
        if(i!=col){
            int val = grid[row][i]+seqn(grid,n,row+1,i,dp);
            mini = min(mini,val);
        }
    }
    return(dp[row][col]=mini);
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            return grid[0][0];
        }
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        int mini = 1e9;
        for(int i=0;i<n;i++){
            int val = grid[0][i]+seqn(grid,n,1,i,dp);
            mini = min(mini,val);
        }
        return(mini);
    }
};