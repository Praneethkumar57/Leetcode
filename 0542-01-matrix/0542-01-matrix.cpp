class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();

            if(r-1>=0 && mat[r-1][c]==1 && vis[r-1][c]==0){
                vis[r-1][c]=t+1;
                q.push({{r-1,c},t+1});
            }

            if(r+1<n && mat[r+1][c]==1 && vis[r+1][c]==0){
                vis[r+1][c]=t+1;
                q.push({{r+1,c},t+1});
            }

            if(c-1>=0 && mat[r][c-1]==1 && vis[r][c-1]==0){
                vis[r][c-1]=t+1;
                q.push({{r,c-1},t+1});
            }

            if(c+1<m && mat[r][c+1]==1 && vis[r][c+1]==0){
                vis[r][c+1]=t+1;
                q.push({{r,c+1},t+1});
            }
        }
        return(vis);
    }
};