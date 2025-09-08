int fn(vector<int>& nums,int n,int value,int index,vector<int>& dp){
    if(value>=n-1){
        return 0;
    }

    if(dp[index]!=-1){
        return(dp[index]);
    }
    int mini = 1e8;
    for(int i=1;i<=nums[index];i++){
        int val1 = 1+fn(nums,n,value+i,index+i,dp);
        mini = min(mini,val1);
    }
    return dp[index] = mini;
}


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        vector<int> dp(n,-1);
        return(fn(nums,n,0,0,dp));
    }
};