class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(i < 2) dp[i] = cost[i];
            else dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};