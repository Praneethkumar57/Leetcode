bool fn(vector<int>& nums,int index,int sum1,int sum2,vector<vector<int>>& dp){
    if(sum1==sum2)return true;
    if(index==0){
        if(sum1+nums[0]==sum2-nums[0])return true;
        return false;
    }
    if(dp[index][sum1]!=-1){
        return(dp[index][sum1]);
    }

    bool nottake = fn(nums,index-1,sum1,sum2,dp);
    bool take=false;
    if(sum1<=sum2){
        take = fn(nums,index-1,sum1+nums[index],sum2-nums[index],dp);
    }
    dp[index][sum1]=(take || nottake);
    return(take || nottake);
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum =0;
        for(auto it:nums){
            sum += it;
        }
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return(fn(nums,n-1,0,sum,dp));
    }
};