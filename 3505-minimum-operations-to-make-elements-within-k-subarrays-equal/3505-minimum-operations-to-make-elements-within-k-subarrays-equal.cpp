class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        set<pair<long long, int>> l, h;
        long long ls = 0, hs = 0;
        vector<long long> vals(n, 0);

        for (int i = 0; i < n; ++i) {
            if (h.empty() || nums[i] >= h.begin()->first) {
                h.insert({nums[i], i});
                hs += nums[i];
            } else {
                l.insert({nums[i], i});
                ls += nums[i];
            }

            if (i >= x) {
                long long val = nums[i - x];
                auto it = l.find({val, i - x});
                if (it != l.end()) {
                    l.erase(it);
                    ls -= val;
                } else {
                    h.erase(h.find({val, i - x}));
                    hs -= val;
                }
            }

            while (h.size() > l.size() + 1) {
                auto it = h.begin();
                long long val = it->first;
                int idx = it->second;
                hs -= val;
                h.erase(it);
                l.insert({val, idx});
                ls += val;
            }

            while (h.size() < l.size()) {
                auto it = prev(l.end());
                long long val = it->first;
                int idx = it->second;
                ls -= val;
                l.erase(it);
                h.insert({val, idx});
                hs += val;
            }

            if (i >= x - 1) {
                long long med = h.begin()->first;
                vals[i] = ((long long)l.size() * med - ls) + (hs - (long long)h.size() * med);
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 0;
        }

        dp[x - 1][1] = vals[x - 1];

        for (int i = x; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + vals[i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};