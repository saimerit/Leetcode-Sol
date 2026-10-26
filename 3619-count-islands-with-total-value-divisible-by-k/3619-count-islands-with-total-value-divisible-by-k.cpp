class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, long& ans){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0) return;
        ans += grid[i][j];
        grid[i][j] = 0;
        dfs(grid, i+1, j, ans);
        dfs(grid, i-1, j, ans);
        dfs(grid, i, j+1, ans);
        dfs(grid, i, j-1, ans);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    long val = 0;
                    dfs(grid, i, j, val);
                    if(!(val % k)) ans++;
                }
            }
        }
        return ans;
    }
};