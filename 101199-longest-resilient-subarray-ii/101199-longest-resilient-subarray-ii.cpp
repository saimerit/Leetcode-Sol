class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int m_len = 0;
        int l = 0;
        while (l < n) {
            int r = l;
            int rem = (nums[l] % k + k) % k; 
            
            while (r < n && (nums[r] % k + k) % k == rem)r++;
            int seg_len = r - l;
            
            for (int L = seg_len; L >= 1; --L) {
                if ((1LL * (L - 1) * rem) % k == 0) {
                    m_len = max(m_len, L);
                    break;
                }
            }   
            l = r;
        }
        return m_len;
    }
};