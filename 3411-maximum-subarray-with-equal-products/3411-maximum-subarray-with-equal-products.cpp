class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            long long p = 1;
            long long g = nums[i];
            long long l = nums[i];

            for(int j = i; j < n; j++){
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if(p == l * g) ans = max(ans, j-i+1);
                if(p > 1e14) break;
            }
        }
        return ans;
    }
};