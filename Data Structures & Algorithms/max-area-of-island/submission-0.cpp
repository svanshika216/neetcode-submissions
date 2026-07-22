class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int area = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if( nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && 
                grid[nrow][ncol] != 0 && !vis[nrow][ncol]){
                area += dfs(grid, vis, nrow, ncol);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                   ans = max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};
