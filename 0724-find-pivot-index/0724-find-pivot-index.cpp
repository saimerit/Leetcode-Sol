class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre = 0;
        int suff = 0;
        int n = nums.size();
        for(int i : nums) suff+= i;
        
        for(int i = 0; i < n; i++){
            suff -= nums[i];
            if(suff == pre) return i;
            pre += nums[i];
        }
        return -1;
    }
};