class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int mx = 0;
        for(int &l : nums){
            mp[l]++;
            mx = max(mx, l);
        }
        vector<int> points(mx+1, 0);
        for(int i = 1; i <= mx; i++){
            points[i] = i * mp[i];
        }
        vector<int> dp(mx+1, 0);
        dp[1] = points[1];
        for(int i = 2; i <= mx; i++){
            dp[i] = max(dp[i-1], points[i] + dp[i-2]);
        }
        return dp[mx];
    }
};