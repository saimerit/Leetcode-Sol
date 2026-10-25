class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || vis[i][j] ||grid[i][j] == 1) return;
        vis[i][j] = 1;
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i, j+1);
        dfs(grid, vis, i, j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0] != 1){
                dfs(grid, vis, i, 0);
            }
            if(!vis[i][m-1] && grid[i][m-1] != 1){
                dfs(grid, vis, i, m-1);
            }
        }
        for(int i = 0; i < m; i++){
            if(!vis[0][i] && grid[0][i] != 1){
                dfs(grid, vis, 0, i);
            }
            if(!vis[n-1][i] && grid[n-1][i] != 1){
                dfs(grid, vis, n-1, i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};