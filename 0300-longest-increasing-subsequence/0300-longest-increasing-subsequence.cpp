int fn(vector<int>& nums,int n,int ind, int prev_ind,vector<vector<int>>& dp){
    if(ind==n){
        return 0;
    }

    if(dp[ind][prev_ind+1]!=-1){
        return(dp[ind][prev_ind+1]);
    }

    int len = 0+fn(nums,n,ind+1,prev_ind,dp);
    if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
        len = max(len,1+fn(nums,n,ind+1,ind,dp));
    }
    return (dp[ind][prev_ind+1] = len);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return(fn(nums,n,0,-1,dp));
    }
};