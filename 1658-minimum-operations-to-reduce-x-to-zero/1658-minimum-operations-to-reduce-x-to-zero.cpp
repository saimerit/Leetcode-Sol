class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long tsum = 0;
        for(int i : nums) tsum+=i;
        long long tar = tsum - x;
        int left = 0;
        int maxlen = -1;
        long long sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(left <= right && sum > tar){
                sum -= nums[left];
                left++;
            }
            if(sum == tar){
                maxlen = max(maxlen, right-left+1);
            }
        }
        if(maxlen == -1) return -1;
        return n - maxlen;
    }
};