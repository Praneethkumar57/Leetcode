bool fn(string& s,string& p,int i,int j,vector<vector<int>>& dp){
    if(i<0 && j<0){
        return true;
    }
    else if(i<0 && j>=0) return false;
    else if(j<0 && i>=0){
        for(int k=0;k<=i;k++){
            if(s[k]!='*') return false;
        }
        return true;
    }

    if(dp[i][j]!=-1){
        return(dp[i][j]);
    }

    if(s[i]==p[j] || s[i]=='?'){
        return(dp[i][j]=fn(s,p,i-1,j-1,dp));
    }
    else if(s[i]=='*'){
        return(dp[i][j]=fn(s,p,i-1,j,dp) || fn(s,p,i,j-1,dp));
    }
    return false;

}

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m = p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return(fn(p,s,m-1,n-1,dp));
    }
};