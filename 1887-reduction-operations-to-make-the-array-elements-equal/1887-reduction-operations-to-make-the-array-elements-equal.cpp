class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ops = 0;
        int sta = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[i-1]){
                sta++;
            }
            ops += sta;
        }
        return ops;
    }
};