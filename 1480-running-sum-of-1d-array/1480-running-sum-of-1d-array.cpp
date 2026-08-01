class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int ps = 0;
        for(int i =0; i < n; i++){
            ps += nums[i];
            ans[i] = ps;
        }
        return ans;
    }
};