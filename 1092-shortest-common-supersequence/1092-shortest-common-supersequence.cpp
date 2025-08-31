int lcs(string& s1,string& s2,int ind1,int ind2,vector<vector<int>>& dp){
    if(ind1<0 || ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return(dp[ind1][ind2]);
    }

    if(s1[ind1]==s2[ind2]){
        return(dp[ind1][ind2] = 1+lcs(s1,s2,ind1-1,ind2-1,dp));
    }
    return(dp[ind1][ind2] = max(lcs(s1,s2,ind1-1,ind2,dp),lcs(s1,s2,ind1,ind2-1,dp)));
}

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int len = lcs(str1,str2,n-1,m-1,dp);
        string t="";
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
                t = t+str1[i];
                i=i-1;
                j=j-1;
            }
            else if(i > 0 && (j == 0 || dp[i-1][j] >= dp[i][j-1])){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(t.begin(),t.end());
        string res="";
        i=0,j=0;
        int k=0;
        while(i<n && j<m && k<len){
            if(str1[i]==t[k] && str2[j]==t[k]){
                res = res+t[k];
                k=k+1;
                i=i+1;
                j = j+1;
            }
            else if(str1[i]!=t[k]){
                res = res+str1[i];
                i = i+1;
            }
            else if(str2[j]!=t[k]){
                res = res+str2[j];
                j=j+1;
            }
        }
        while(i<n){
            res=res+str1[i];
            i=i+1;
        }
        while(j<m){
            res=res+str2[j];
            j=j+1;
        }
        return res;
    }
};