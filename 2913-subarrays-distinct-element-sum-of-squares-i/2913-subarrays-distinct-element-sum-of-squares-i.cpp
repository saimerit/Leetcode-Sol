class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            set<int> st;
            for(int k = i; k < n; k++){
                st.insert(nums[k]);
                ans += st.size() * st.size();
            }
        }
        return ans;
    }
};