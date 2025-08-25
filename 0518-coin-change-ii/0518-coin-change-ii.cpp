int fn(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
    if(index<0){
        if(amount==0)return 1;
        return 0;
    }
    if(amount == 0){
        return 1;
    }

    if(dp[index][amount]!=-1){
        return(dp[index][amount]);
    }

    int notpick = fn(coins,amount,index-1,dp);
    int pick=0;
    if(coins[index]<=amount){
        pick = fn(coins,amount-coins[index],index,dp);
    }
    return(dp[index][amount]=notpick+pick);
}

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return(fn(coins,amount,n-1,dp));
    }
};