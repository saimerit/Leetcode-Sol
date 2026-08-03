class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& board, int n, int m){
        if(i >= m || j >= n || i < 0 || j < 0|| vis[i][j] || board[i][j] != 'O') return;
        board[i][j] = 'T';
        vis[i][j] = true;
        dfs(i-1, j, vis, board, n, m);
        dfs(i, j+1, vis, board, n, m);
        dfs(i+1, j, vis, board, n, m);
        dfs(i, j-1, vis, board, n, m);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') q.push({0, j});
        }
        for(int j = 0; j < n; j++){
            if(board[m-1][j] == 'O') q.push({m-1, j});
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') q.push({i, 0});
        }
        for(int i = 0; i < m; i++){
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(!vis[i][j]) dfs(i, j, vis, board, n, m);
        }
        for(int k = 0; k < m; k++){
            for(int l = 0; l < n; l++){
                if(board[k][l] == 'O' && !vis[k][l]) board[k][l] = 'X';
            }
        }
        for(int k = 0; k < m; k++){
            for(int l = 0; l < n; l++){
                if(board[k][l] == 'T') board[k][l] = 'O';
            }
        }
    }
};