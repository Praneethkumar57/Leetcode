void dfs(int node,int n,vector<int>& visited,vector<vector<int>>& isConnected){
    visited[node]=1;
    for(int i=0;i<n;i++){
        if(isConnected[node][i]==1){
            if(visited[i]==0){
                dfs(i,n,visited,isConnected);
            }
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                cnt++;
                dfs(i,n,visited,isConnected);
            }
        }
        return cnt;
    }
};