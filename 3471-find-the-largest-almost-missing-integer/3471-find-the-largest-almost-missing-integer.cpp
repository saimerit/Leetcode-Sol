class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            unordered_map<int, int>cnts;
            for(int num: nums){
                cnts[num]++;
            }
            int m_val = -1;
            for(auto const& [num, count] : cnts){
                if(count == 1) m_val = max(m_val, num);
            }
            return m_val;
        }
        int f_el = nums[0];
        int l_ele = nums[n-1];

        if(f_el == l_ele){
            return -1;
        }   
        int f_cnt = 0;
        int l_cnt = 0;
        for(int num : nums){
            if(num == f_el) f_cnt++;
            if(num == l_ele) l_cnt++;
        }
        int ans = -1;
        if(f_cnt == 1)ans = max(ans, f_el);
        if(l_cnt == 1) ans = max(ans, l_ele);
        return ans;
    }

};