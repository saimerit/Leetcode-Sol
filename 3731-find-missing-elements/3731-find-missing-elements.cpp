class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mi = nums[0];
        int ma = nums.back();
        vector<int> ans;
        for(int i = mi + 1; i < ma; i++){
            bool f = false;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    f = true;
                    break;
                }
            }
            if(!f) ans.push_back(i);
        }
        return ans;
    }
};