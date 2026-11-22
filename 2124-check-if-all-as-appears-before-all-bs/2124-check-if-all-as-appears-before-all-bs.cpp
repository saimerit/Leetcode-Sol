class Solution {
public:
    bool checkString(string s) {
        bool cntb = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'b') cntb = true;
            else if(cntb) return false;
        }
        return true;
    }
};