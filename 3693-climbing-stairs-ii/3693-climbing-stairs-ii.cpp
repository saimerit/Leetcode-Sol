class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==1) return costs[0] + 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = costs[1] + min(4, dp[1] + 1);
        for(int i = 3; i < n+1; i++){
            dp[i] = costs[i-1] + min(dp[i-1] + 1, min(dp[i-2] + 4, dp[i-3] + 9));
        }
        return dp[n];
    }
};