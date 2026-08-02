class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for(int i = n-1; i >= 0; i--){
            dp[i] = piles[i];
            for(int j = i+1; j < n; j++){
                int left = piles[i] - dp[j];
                int right = piles[j] - dp[j-1];
                dp[j] = max(left, right);
            }
        }
        return dp[n-1] >= 0;
    }
};