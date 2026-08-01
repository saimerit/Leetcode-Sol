class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i = n-1; i >= 0; i--){
            dp[i] = nums[i];
            for(int j = i + 1; j < n; j++){
                int left = nums[i] - dp[j];
                int right = nums[j] - dp[j-1];
                dp[j] = max(left, right);
            }
        }   
        return dp[n-1] >= 0;
    }
};