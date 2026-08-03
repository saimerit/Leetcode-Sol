class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int nrob = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int newRob = nrob + nums[i];
            int newNrob = max(rob, nrob);
            rob = newRob;
            nrob = newNrob;
        }
        return max(nrob, rob);
    }
};