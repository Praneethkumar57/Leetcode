int lcs(string& s, string& t, int index1,int index2,vector<vector<int>>& dp){
    if(index1<0 || index2<0){
        return 0;
    }
    if(dp[index1][index2]!=-1){
        return(dp[index1][index2]);
    }
    
    if(s[index1]==t[index2]){
        return (dp[index1][index2]= 1+lcs(s,t,index1-1,index2-1,dp));
    }
    return(dp[index1][index2]=max(lcs(s,t,index1-1,index2,dp),lcs(s,t,index1,index2-1,dp)));

}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string t = s;
        reverse(t.begin(),t.end());
        return(lcs(s,t,n-1,n-1,dp));
    }
};