class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int res = 0;
        while(l < r){
            int wid = r - l;
            res = max(res, wid*(min(height[l], height[r])));
            if (height[l] < height[r]) l += 1;
            else r-=1;
        }
        return res;
    }
};