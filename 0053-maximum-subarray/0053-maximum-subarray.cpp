class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currs = nums[0];
        int maxs = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            currs = max(currs + nums[i], nums[i]);
            maxs = max(maxs, currs);
        }
        return maxs;
    }
};