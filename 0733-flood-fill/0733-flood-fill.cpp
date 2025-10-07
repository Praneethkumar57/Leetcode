bool isSame(int sr1,int sc1, vector<vector<int>>& image,int sr2,int sc2){
    if(image[sr1][sc1]==image[sr2][sc2]){
        return true;
    }
    return false;
}

void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& vis,int n,int m){
    vis[sr][sc]=1;
    if(sr-1>=0 && vis[sr-1][sc]==0 && isSame(sr-1,sc,image,sr,sc)){
        dfs(sr-1,sc,image,vis,n,m);
    }

    if(sc-1>=0 && vis[sr][sc-1]==0 && isSame(sr,sc-1,image,sr,sc)){
        dfs(sr,sc-1,image,vis,n,m);
    }

    if(sr+1<n && vis[sr+1][sc]==0 && isSame(sr+1,sc,image,sr,sc)){
        dfs(sr+1,sc,image,vis,n,m);
    }

    if(sc+1<m && vis[sr][sc+1]==0 && isSame(sr,sc+1,image,sr,sc)){
        dfs(sr,sc+1,image,vis,n,m);
    }
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(sr,sc,image,vis,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    image[i][j]=color;
                }
            }
        }
        return image;
    }
};