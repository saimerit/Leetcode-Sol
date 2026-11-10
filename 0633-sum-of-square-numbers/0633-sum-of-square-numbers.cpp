class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = sqrt(c);
        while(left <= right){
            long csum = left * left + right * right;
            if(csum == c) return true;
            else if(csum < c) left++;
            else right--;
        }
        return false;
    }
};