class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int mik = 0, mak = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[mik]){
                mik = i;
            }
            if(nums[i] > nums[mak]){
                mak = i;
            }
        }
        int L = min(mik, mak);
        int R = max(mik, mak);
        return min({R+1, n-L, (L+1)+(n-R)});
    }
};