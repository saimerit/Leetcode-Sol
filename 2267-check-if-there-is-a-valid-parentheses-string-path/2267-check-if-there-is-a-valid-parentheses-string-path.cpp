class Solution {
public:
    bool f(vector<vector<char>>& grid, int i, int j, int l, vector<vector<vector<int>>>& t){
        int n = grid.size();
        int m = grid[0].size();
        l += (grid[i][j] == '(' ? 1 : -1);
        if (l < 0 || l > (n + m) / 2) return false;
        if(i == n-1 && j == m-1){
            return l == 0;
        }
        if(t[i][j][l] != -1) return t[i][j][l];
        bool down = (i+1 < n) && f(grid, i+1, j, l, t);
        bool right = (j+1 < m) && f(grid, i, j+1, l, t);
        return t[i][j][l] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if((m+n-1)%2 != 0) return false;
        vector<vector<vector<int>>> t(n, vector<vector<int>>(m, vector<int>(m+n, -1)));
        
        return f(grid, 0, 0, 0, t);
    }
};