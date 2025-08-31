int fn(string& word1,string& word2,int ind1,int ind2,vector<vector<int>>& dp){
    if(ind1==-1){
        return(ind2+1);
    }
    if(ind2==-1){
        return(ind1+1);
    }

    if(dp[ind1][ind2]!=-1){
        return(dp[ind1][ind2]);
    }

    if(word1[ind1]==word2[ind2]){
        return(fn(word1,word2,ind1-1,ind2-1,dp));
    }
    int val1 = 1+ fn(word1,word2,ind1,ind2-1,dp); // we are inserting value in word1 so reduce value in ind2 and ind1 will be remains in same index
    int val2 = 1+ fn(word1,word2,ind1-1,ind2,dp); // this is deletion operation where we are deleting ind1 value so move ind1-1 and ind2 remains same
    int val3 = 1+ fn(word1,word2,ind1-1,ind2-1,dp); // this is replace operation where we are replacing str2 char in str1 and moving both by 1 position
    return(dp[ind1][ind2]= min(val1,min(val2,val3)));
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return(fn(word1,word2,n-1,m-1,dp));
    }
};