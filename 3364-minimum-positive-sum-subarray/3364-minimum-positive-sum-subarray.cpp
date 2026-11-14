class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = l; i <= r; i++){
            int temp;
            for(int j = 0; j <= n - i; j++){
                temp = 0;
                for(int k = 0; k < i; k++){
                    temp += nums[j+k];
                }
                if(temp > 0)ans = min(ans, temp);
            }
        }
        return (ans == INT_MAX ? -1:ans);
    }
};