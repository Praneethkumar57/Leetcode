int fn(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
    if(amount == 0){
        return 0;
    }
    if(index==0){
        if(amount%coins[0]==0){
            return(amount/coins[0]);
        }
        return(1e9);
    }
    if(dp[index][amount]!=-1){
        return(dp[index][amount]);
    }

    int nottake = fn(coins,amount,index-1,dp);
    int take = 1e9;
    if(amount>=coins[index]){
        take = 1+fn(coins,amount-coins[index],index,dp);
    }
    return(dp[index][amount]=min(take,nottake));
}


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int val = fn(coins,amount,n-1,dp);
        if(val!=1e9){
            return val;
        }
        return(-1);
    }
};