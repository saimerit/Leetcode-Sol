class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum+=i;
        if(sum % 2 == 1) return false;
        int tar = sum/2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int t = 0; t < tar + 1; t++){
                bool nottake = dp[i-1][t];
                bool take = false;
                if(nums[i] <= t) take = dp[i-1][t-nums[i]];
                dp[i][t] = take || nottake;
            }
        }
        return dp[n-1][tar];
    }
};