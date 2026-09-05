class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> store(n, vector<int>(2));
        int m = nums[0];
        for(int i = 0; i < n; i++){
            if(m < nums[i]) m = nums[i];
            store[i][0] = m;
        }
        int mi = nums[n-1];
        for(int i = n-1; i >= 0; i--){
            if(m > nums[i]) m = nums[i];
            store[i][1] = m;
        }
        vector<int> ins(n);
        for(int i = 0; i < n; i++) ins[i] = store[i][0] - store[i][1];
        for(int i = 0; i < n; i++){
            if(ins[i] <= k) return i;
        }
        return -1;
    }
};