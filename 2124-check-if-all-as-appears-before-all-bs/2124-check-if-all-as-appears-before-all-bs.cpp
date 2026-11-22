class Solution {
public:
    bool checkString(string s) {
        int cntb = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'b') cntb++;
            else if(cntb > 0) return false;
        }
        return true;
    }
};