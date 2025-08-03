int robber(vector<int>& temp,int index,vector<int>& dp){
    if(index==0) return temp[0];
    if(index<0)return 0;

    if(dp[index]!=-1)return dp[index];
    int pick = temp[index]+robber(temp,index-2,dp);
    int notpick = 0+robber(temp,index-1,dp);
    dp[index]=max(pick,notpick);
    return(dp[index]);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(),-1);
        vector<int> dp2(temp2.size(),-1);
        int res1 = robber(temp1,temp1.size()-1,dp1);
        int res2 = robber(temp2,temp2.size()-1,dp2);
        return(max(res1,res2));
    }
};