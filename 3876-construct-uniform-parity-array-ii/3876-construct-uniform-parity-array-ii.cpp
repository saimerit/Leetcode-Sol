class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool t = true;
        int n = nums1.size();
        int m = nums1[0];
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 != 0) t = false;
            if(m > nums1[i]) m = nums1[i];
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 != 1) f = false;
        }
        return t || f || (m%2 == 1);
    }
};