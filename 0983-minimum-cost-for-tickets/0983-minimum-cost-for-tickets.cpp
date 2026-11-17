class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        int dayIdx = 0;
        vector<int> dp(lastDay + 1, 0);
        for(int i = 1; i <= lastDay; i++){
            if(i != days[dayIdx]) dp[i] = dp[i-1];
            else{
                int cost1 = dp[max(0, i-1)] + costs[0];
                int cost7 = dp[max(0, i-7)] + costs[1];
                int cost30 = dp[max(0, i-30)] + costs[2];
                dp[i] = min({cost1, cost7, cost30});
                dayIdx++;
            }
        }
        return dp[lastDay];
    }
};