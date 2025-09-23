bool check_string(string& str1,string& str2){
    int n=str1.size();
    int m=str2.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(str1[i]==str2[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(i==n && j==m){
        return true;
    }
    else if(i==n && (j+1)==m){
        return true;
    }
    return false;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for(auto it:words){
            for(auto i:it){
                cout<<i;
            }
            cout<<" ";
        }
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((words[j].size()+1 == words[i].size())){
                    if(check_string(words[j],words[i])){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};