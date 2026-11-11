class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxVal) maxVal = nums[i];
        }

        vector<int> p(maxVal+1, 0);
        for(int num : nums){
            p[num] += num;
        }

        int prev1 = 0;
        int prev2 = 0;
        for(int i = 1; i <= maxVal; i++){
            int curr = max(prev1, prev2 + p[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};