class Solution {
public:
    bool checkValidString(string s) {
        int d2 = 0;
        int d3 = 0;
        for(char i : s){
            if(i == '('){
                d2++;
                d3++;
            }else if(i == ')'){
                d2--;
                d3--;
            }else{
                d3--;
                d2++;
            }
            if(d2 < 0) return false;
            if(d3 < 0) d3 = 0;
        }
        return d3 == 0;
    }
};