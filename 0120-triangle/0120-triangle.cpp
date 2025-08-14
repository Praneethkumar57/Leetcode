int fn(vector<vector<int>>& triangle,int n,vector<vector<int>>& dp,int row,int col){
    if(row==n-1){
        return(triangle[row][col]);
    }
    if(dp[row][col]!=1e9){
        return dp[row][col];
    }

    int down = triangle[row][col] +fn(triangle,n,dp,row+1,col);
    int diagonal = triangle[row][col] + fn(triangle,n,dp,row+1,col+1);
    dp[row][col] = min(down,diagonal);
    return(dp[row][col]);
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        return(fn(triangle,n,dp,0,0));
    }
};