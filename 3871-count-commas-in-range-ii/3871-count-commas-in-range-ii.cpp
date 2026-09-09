class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(int i = 1; i < 6; i++) {
            if(pow(1000, i)-1 > n) break;
            ans += n- (pow(1000, i)-1);
        }
        return ans;
    }
};