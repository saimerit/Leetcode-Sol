class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int xo = 0;
        for(int i = 0; i < n; i++){
            xo ^= nums[i];
            if(nums[i] == 0) l+=1;
        }
        if(xo == 0 && l == n) return 0;
        if(xo == 0) return n-1;
        return n;
    }
};