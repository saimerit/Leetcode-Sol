class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int right_even = 0, right_odd = 0;
        int left_even = 0, left_odd = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) right_even += nums[i];
            else right_odd += nums[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) right_even -= nums[i];
            else right_odd -= nums[i];

            if (left_even + right_odd == left_odd + right_even) {
                cnt++;
            }

            if (i % 2 == 0) left_even += nums[i];
            else left_odd += nums[i];
        }

        return cnt;
    }
};