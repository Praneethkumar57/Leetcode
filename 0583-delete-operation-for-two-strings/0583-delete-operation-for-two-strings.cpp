int lcs(string& word1,string& word2,int ind1,int ind2,vector<vector<int>>& dp){
    if(ind1<0 || ind2<0){
        return 0;
    }

    if(dp[ind1][ind2]!=-1){
        return(dp[ind1][ind2]);
    }

    if(word1[ind1]==word2[ind2]){
        return(dp[ind1][ind2]=1+lcs(word1,word2,ind1-1,ind2-1,dp));
    }
    return(dp[ind1][ind2]=max(lcs(word1,word2,ind1-1,ind2,dp),lcs(word1,word2,ind1,ind2-1,dp)));
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int val = lcs(word1,word2,n-1,m-1,dp);
        int res = n-val;
        return(res+(m-val));
    }
};