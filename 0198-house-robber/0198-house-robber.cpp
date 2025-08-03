int robber(vector<int>& nums,int index,vector<int>& dp){
    if(index == 0)return nums[index];
    if(index<0)return 0;

    if(dp[index]!=-1) return dp[index];

    int pick = nums[index]+robber(nums,index-2,dp);
    int nonpick = 0+robber(nums,index-1,dp);

    dp[index]=max(pick,nonpick);
    return(dp[index]);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return(robber(nums,n-1,dp));
    }
};