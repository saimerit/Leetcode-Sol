class Solution {
public:
    int f(int i, vector<int>& arr, vector<int>& dp, vector<bool>& vis){
        if(arr[i] == 0) return 1;
        if(dp[i] != -1) return dp[i];
        if(vis[i]) return 0;
        vis[i] = true;
        int right=0, left =0;
        if(i+arr[i] < arr.size()) right = f(i+arr[i], arr, dp, vis);
        if(i-arr[i] >= 0) left = f(i-arr[i], arr, dp, vis);
        vis[i] = false;
        return dp[i] = right || left;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(), -1);
        vector<bool> vis(arr.size(), false);
        int j = f(start, arr, dp, vis);
        return dp[start];
    }
};