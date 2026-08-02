class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int prev = 1;
        int curr = 2;
        int newe;
        for(int i = 2; i<n; i++){
            newe = prev + curr;
            prev = curr;
            curr = newe;
        }
        return newe;
    }
};