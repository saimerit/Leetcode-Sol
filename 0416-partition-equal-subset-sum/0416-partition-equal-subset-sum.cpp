class Solution {
public:
    bool subSum(vector<int>& nums, int sum, int n){
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));
        for(int i = 0; i < n+1; i++) t[i][0] = true;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i : nums){
            s += i;
        }
        if(s%2 != 0) return false;
        return subSum(nums, s/2, nums.size());
    }
};