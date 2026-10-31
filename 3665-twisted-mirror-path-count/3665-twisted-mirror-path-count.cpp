class Solution {
public:
    int n, m;
    long long int mod = 1e9 + 7;
    long long int dfs(vector<vector<int>>& grid, vector<vector<vector<long long int>>>& dp, int i, int j, int dir){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if(grid[i][j] == 1){
            if(dir == 0) dp[i][j][dir] = dfs(grid, dp, i+1, j, 1);
            else dp[i][j][dir] = dfs(grid, dp, i, j+1, 0);
        }else{
            dp[i][j][dir] = (dfs(grid, dp, i, j+1, 0) + dfs(grid, dp, i+1, j, 1)) % mod;
        }
        return dp[i][j][dir];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(m, {-1, -1}));
        return dfs(grid, dp, 0, 0, 0);
    }
};