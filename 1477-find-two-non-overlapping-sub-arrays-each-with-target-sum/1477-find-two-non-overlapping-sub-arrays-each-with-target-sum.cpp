class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ps = 0;
        int res = INT_MAX;
        int l = 0;
        vector<int> dp(n, INT_MAX);
        for(int r = 0; r < n; r++){
            ps += arr[r];
            while(ps > target){
                ps-=arr[l];
                l++;
            }
            dp[r] = (r-1>=0 ? dp[r-1] : INT_MAX);
            if(ps == target){
                int curr = r-l+1;
                if(l > 0 && dp[l-1] != INT_MAX)res = min(res, curr + dp[l-1]);
                if(r > 0)dp[r] = min(dp[r], curr);
                else dp[r] = curr;
            }else{
                if(r > 0){
                    dp[r] = dp[r-1];
                }
            }
        }
        return (res == INT_MAX ? -1 : res);
    }
};