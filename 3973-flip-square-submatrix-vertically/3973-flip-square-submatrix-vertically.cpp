class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,int y, int k) {
        if (k <= 1) {
            return grid;
        }
        int n = x + k - 1;
        while (x < n) {
            for (int j = y; j < y + k; j++) {
                swap(grid[x][j], grid[n][j]);
            }
            x++;
            n--;
        }
        return (grid);
    }
};