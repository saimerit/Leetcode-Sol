class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<vector<int>> dp = matrix;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int ch1 = dp[i-1][j];
                int ch2 = (j>0) ? dp[i-1][j-1] : INT_MAX;
                int ch3 = (j+1 <n ) ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] += min(ch1, min(ch2, ch3));
            }
        }
        int mi = INT_MAX;
        for(int i = 0; i < n; i++){
            if(mi > dp[n-1][i]) mi = dp[n-1][i];
        }
        return mi;
    }
};