class Solution {
public:
    int numOfWays(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        
        int n = nums.size();
        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        
        auto dfs = [&](auto& self, vector<int>& nums) -> long long {
            int m = nums.size();
            if (m <= 2) return 1;
            
            vector<int> left;
            vector<int> right;
            
            for (int i = 1; i < m; ++i) {
                if (nums[i] < nums[0]) {
                    left.push_back(nums[i]);
                } else {
                    right.push_back(nums[i]);
                }
            }
            
            return (self(self, left) * self(self, right) % MOD) * comb[m - 1][left.size()] % MOD;
        };
        
        return dfs(dfs, nums) - 1;
        
    }
};