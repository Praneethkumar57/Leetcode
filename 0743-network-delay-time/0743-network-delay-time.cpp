class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({k,0});
        dist[k]=0;
        while(!pq.empty()){
            pair<int,int> ele = pq.top();
            int node = ele.first;
            int wt=ele.second;
            pq.pop();

            if(wt>dist[node])continue;

            for(auto it:adj[node]){
                if(wt+it.second < dist[it.first]){
                    dist[it.first]=wt+it.second;
                    pq.push({it.first,dist[it.first]});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};