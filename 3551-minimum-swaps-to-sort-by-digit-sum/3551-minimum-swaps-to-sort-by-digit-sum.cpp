class Solution {
public:
    int dsum(int n){
        int ans = 0;
        while(n > 0){
            ans += (n%10);
            n /= 10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            int sum_a = dsum(a.first);
            int sum_b = dsum(b.first);
            if (sum_a == sum_b) {
                return a.first < b.first;
            }
            return sum_a < sum_b;
        });
        int swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};