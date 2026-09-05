class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return 0;
        if(n == 2) return abs(stones[1] - stones[0]);
        int l = 0;
        for(int i = 2; i < n; i++){
            l = max(l, max(abs(stones[i] - stones[i-1]), abs(stones[i] - stones[i-2])));
        }
        return l;
    }
};