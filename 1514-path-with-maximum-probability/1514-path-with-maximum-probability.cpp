class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double pb = succProb[i];
            adj[u].push_back({v,pb});
            adj[v].push_back({u,pb});
        }
        vector<double> prob(n,0);

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        prob[start_node]=1;
        while(!pq.empty()){
            pair<double,int> ele = pq.top();
            int node = ele.second;
            double p = ele.first;
            pq.pop();

            if(node==end_node){
                return p;
            }

            for(auto it:adj[node]){
                int newnode = it.first;
                double newp = it.second;

                if((p*newp)>prob[newnode]){
                    prob[newnode]=p*newp;
                    pq.push({prob[newnode],newnode});
                }
            }
        }
        return prob[end_node];
    }
};