class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<char, int> st;
        while(right < s.length()){
            st[s[right]]++;
            while(st[s[right]] > 2){
                st[s[left]]--;
                left++;
            }
            res = max(res, (right - left) +1);
            right++;
        }
        return res;
    }
};