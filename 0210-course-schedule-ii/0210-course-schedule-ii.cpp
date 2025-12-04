int t=0;

bool dfs(int i,vector<int>& vis,vector<vector<int>>& adj,vector<pair<int,int>>& time,vector<int>& res){
    vis[i]=1;
    t++;
    time[i].first=t;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(!dfs(it,vis,adj,time,res))return false;
        }
        else if(vis[it] && time[it].second==-1){
            return false;
        }
    }
    time[i].second=++t;
    res.push_back(i);
    return true;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int> res;
        vector<int> vis(numCourses,0);
        vector<pair<int,int>> time(numCourses,{-1,-1});
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i,vis,adj,time,res))return {};
            }
        }
        return res;
    }
};