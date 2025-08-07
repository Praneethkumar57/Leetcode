bool isConnected(int row,int col,int n,int m,vector<vector<char>>& grid){
    if(grid[row][col]=='1'){
        return true;
    }
    return false;
}

void dfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& visited){
    visited[row][col]=1;

    if(col-1>=0 && isConnected(row,col-1,n,m,grid) && visited[row][col-1]==0){
        dfs(row,col-1,n,m,grid,visited);
    }

    if(row-1>=0 && isConnected(row-1,col,n,m,grid) && visited[row-1][col]==0){
        dfs(row-1,col,n,m,grid,visited);
    }

    if(col+1>=0 && col+1<m && isConnected(row,col+1,n,m,grid) && visited[row][col+1]==0){
        dfs(row,col+1,n,m,grid,visited);
    }

    if(row+1>=0 && row+1<n && isConnected(row+1,col,n,m,grid) && visited[row+1][col]==0){
        dfs(row+1,col,n,m,grid,visited);
    }
    
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(visited[row][col]==0 && grid[row][col]=='1'){
                    cnt++;
                    dfs(row,col,n,m,grid,visited);
                }
            }
        }
        return cnt;
    }
};