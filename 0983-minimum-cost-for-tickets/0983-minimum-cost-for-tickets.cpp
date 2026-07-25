class Solution {
public:
    int fn(int ind,vector<int>& days,vector<int>& costs,vector<int>& dp){
        if(ind==days.size())return 0;

        if(dp[ind]!=-1)return dp[ind];
        int v1=INT_MAX, v2=INT_MAX, v3=INT_MAX;
        v1 = fn(ind+1,days,costs,dp)+costs[0];
        int ind1 = upper_bound(days.begin(),days.end(),days[ind]+6)-days.begin();
        v2 = fn(ind1,days,costs,dp)+costs[1];
        int ind2 = upper_bound(days.begin(),days.end(),days[ind]+29)-days.begin();
        v3 = fn(ind2, days,costs,dp)+costs[2];
        return dp[ind]=min(v1,min(v2,v3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return fn(0,days,costs,dp);
    }
};