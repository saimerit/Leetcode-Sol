class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if(n <= k) return s;
        string kl = "";
        for(int i = 0; i < n;){
            int temp = 0;
            for(int j = 0; j < k && i < n; j++, i++){
                temp += (s[i] - '0');
            }
            kl += to_string(temp);
        }
        return (kl.length() <= k) ? kl : digitSum(kl, k);
    }
};