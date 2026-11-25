class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        long long base = *max_element(nums.begin(), nums.end()) + 1;
        int n = nums.size();

        auto check = [&](int size) -> bool {
            unordered_map<long long, int> seen;
            long long h = 0;
            for (int i = 0; i < size; ++i) {
                h = (h * base + nums[i]) % MOD;
            }
            seen[h]++;

            long long p = power(base, size - 1, MOD);
            for (int i = size; i < n; ++i) {
                h = (h - (p * nums[i - size]) % MOD + MOD) % MOD;
                h = (h * base + nums[i]) % MOD;
                seen[h]++;
            }

            for (const auto& [key, val] : seen) {
                if (val == 1) return true;
            }
            return false;
        };

        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};