int seqn(vector<int>& cost,vector<int>& dp,int index){
    if(index==0){
        return(cost[0]);
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    int onestep =cost[index]+seqn(cost,dp,index-1);
    int twostep = cost[index]+seqn(cost,dp,index-2);
    dp[index]=min(onestep,twostep);
    return(dp[index]);
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int val1 = seqn(cost,dp,n-1);
        int val2 = seqn(cost,dp,n-2);
        return(min(val1,val2));
    }
};