int fn(vector<int>& nums,int target,int index,int sum1,int sum2,vector<vector<int>>& dp){
    // if(sum1-sum2==target){
    //     return 1;
    // }
    if(index<0){
        if(sum1-sum2==target)return 1;
        return 0;
    }

    if(dp[index][sum1]!=-1){
        return(dp[index][sum1]);
    }
    int notpick = fn(nums,target,index-1,sum1,sum2,dp);
    int pick = fn(nums,target,index-1,sum1+nums[index],sum2-nums[index],dp);
    return(dp[index][sum1]=notpick+pick);
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return(fn(nums,target,n-1,0,sum,dp));
    }
};