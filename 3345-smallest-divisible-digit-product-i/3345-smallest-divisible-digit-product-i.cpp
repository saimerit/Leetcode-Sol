class Solution {
public:
    int dprod(int n){
        int ans = 1;
        while(n > 0){
            ans *= n%10;
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(dprod(n) % t != 0) n++;
        return n;
    }
};