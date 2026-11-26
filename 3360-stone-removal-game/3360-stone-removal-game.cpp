class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        while(n >= k){
            n -= k--;
            if(n==0 || n < k) return true;
            n -= k--;
        }
        return false;
    }
};