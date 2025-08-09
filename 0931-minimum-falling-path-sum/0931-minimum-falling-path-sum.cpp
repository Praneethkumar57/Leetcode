int seqn(vector<vector<int>>& matrix,int n,vector<vector<int>>& dp, int row,int col){
    if(col<0 || col>=n){
        return 1e9;
    }
    if(row == n-1){
        return matrix[n-1][col];
    }
    if(dp[row][col]!=1e9){
        return dp[row][col];
    }

    
    int val1 = seqn(matrix,n,dp,row+1,col-1);
    int val2 = seqn(matrix,n,dp,row+1,col);
    int val3 = seqn(matrix,n,dp,row+1,col+1);
    
    int mini = min(val1,min(val2,val3));
    dp[row][col] = matrix[row][col]+mini;
    return(dp[row][col]);
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            int val = seqn(matrix,n,dp,0,i);
            mini = min(mini,val);
        }
        return(mini);
    }
};