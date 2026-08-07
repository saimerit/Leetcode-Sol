class Solution {
public:
    int countNeighbours(int r, int c, vector<vector<int>>& board, int n, int m){
        int ans = 0;
        for(int i = r-1; i < r+2; i++){
            for(int j = c-1; j < c+2; j++){
                if((i==r && j == c) || i < 0 || j < 0 || i == n || j == m) continue;
                if(board[i][j] == 1 || board[i][j] == 3) ans++;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                int nei = countNeighbours(r, c, board, n, m);
                if(board[r][c]){
                    if(nei == 2 || nei == 3) board[r][c] = 3;
                }else if (nei == 3){
                    board[r][c] = 2;
                }
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(board[r][c] == 1) board[r][c] = 0;
                else if(board[r][c] == 2 || board[r][c] == 3) board[r][c] = 1;
            }
        }
    }
};