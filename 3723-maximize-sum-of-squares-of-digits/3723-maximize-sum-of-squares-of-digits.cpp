class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while(sum){
            int use = min(sum, 9);
            sum -= use;
            res += '0' + use;
        }
        int r = res.length();
        if(r > num) return "";
        res.append(num - r, '0');
        return res;
    }
};