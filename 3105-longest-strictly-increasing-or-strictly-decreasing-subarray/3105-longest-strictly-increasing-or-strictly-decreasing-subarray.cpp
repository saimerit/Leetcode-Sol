class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                inc++;
            }else{
                ans = max(ans, inc);
                inc = 1;
            }
            if(nums[i] < nums[i-1]){
                dec++;
            }else{
                ans = max(ans, dec);
                dec = 1;
            }
        }   
        ans = max(ans, max(inc, dec));
        return ans;
    }
};