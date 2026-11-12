class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp.push(nums[i]);
        }
        for(int i = 1; i <= k-1; i++){
            mp.pop();
        }
        return mp.top();
    }
};