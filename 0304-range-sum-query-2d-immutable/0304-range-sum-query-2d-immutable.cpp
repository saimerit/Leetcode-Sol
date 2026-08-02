class NumMatrix {
private:
    vector<vector<int>> ans;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        if (n == 0) return;
        int m = (int)mat[0].size();
        ans.assign(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j+1] = ans[i][j] + mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; ++r) {
            sum += ans[r][col2+1] - ans[r][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */