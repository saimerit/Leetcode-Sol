class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||grid[i][j] != '1') return;
        vis[i][j] = true;
        dfs(i-1, j, vis, grid, n, m);
        dfs(i, j+1, vis, grid, n, m);
        dfs(i+1, j, vis, grid, n, m);
        dfs(i, j-1, vis, grid, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();    
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int k = 0; k < n; k++){
            for(int l = 0; l < m; l++){
                if(!vis[k][l] && grid[k][l] == '1'){
                    dfs(k, l, vis, grid, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};