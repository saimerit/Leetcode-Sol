class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int curr, vector<vector<vector<int>>>& memo){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m) return INT_MAX;
        curr ^= grid[i][j];
        if(i == n - 1 && j == m-1){
            return curr;
        }
        if(memo[i][j][curr] != -1) return memo[i][j][curr];
        int md = dfs(grid, i+1, j, curr, memo);
        int mr = dfs(grid, i, j+1, curr, memo);
        return memo[i][j][curr] = min(md, mr);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(grid, 0, 0, 0, memo);
    }
};