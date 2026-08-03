class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int ts = nums[i] + nums[l] + nums[r];
                if(ts> 0) r--;
                else if(ts < 0) l++;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    while(nums[l] == nums[l-1] && l < r)l++;
                }
            }
        }
        return ans;
    }
};