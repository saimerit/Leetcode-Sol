class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30, 0);
        for(int n : nums){
            for(int i = 0; i < 30; i++){
                bits[i] += (n >> i) & 1;
            }
        }
        long long res = 0;
        for(int j = 0; j < k; j++){
            long long n = 0;
            for(int i = 0; i < 30; i++){
                if(bits[i] > 0){
                    n |= 1 << i;
                    bits[i] -= 1;
                }
            }
            res = (res + (n*n)%(1000000007)) % 1000000007;
        }
        return (int)res;
    }
};