class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        queue<pair<pair<int, int>, char>> q;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') q.push({{i, j}, board[i][j]});
            }
        }
        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            char val = q.front().second;
            q.pop();
            for(int k = 0; k < 9; k++){
                if(board[i][k] == val && k != j) return false;
            }
            for(int k = 0; k < 9; k++){
                if(board[k][j] == val && k != i) return false;
            }
            int startRow = (i/3) * 3;
            int startCol = (j/3) * 3;
            for(int r = startRow; r < startRow + 3; r++){
                for(int c = startCol; c < startCol + 3; c++){
                    if(board[r][c] == val && (r != i || c != j)) return false;
                }
            }
        }
        return true;
    }
};