void dfs(int node, vector<vector<int>>& isConnected, int vis[],int n){
    vis[node]=1;
    for(int i=0;i<n;i++){
        if(isConnected[node][i]==1){
            if(!vis[i]){
                dfs(i,isConnected,vis,n);
            }
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis,n);
            }
        }
        return cnt;
    }
};