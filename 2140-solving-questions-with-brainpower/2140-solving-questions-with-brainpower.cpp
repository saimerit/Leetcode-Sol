class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        for(int i = n-1; i >= 0; --i){
            long long p = questions[i][0];
            int bp = questions[i][1];

            long long solve = p;
            int next_idx = i + bp + 1;
            if(next_idx < n) solve += dp[next_idx];

            long long skip = dp[i+1];
            dp[i] = max(skip, solve);
        }
        return dp[0];
    }
};