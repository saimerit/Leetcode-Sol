class Solution {
public:
    int scoreOfParentheses(string s) {
        int d = 0;
        char prev;
        int r = 0;
        for(char i : s){
            if(i == ')'){
                d--;
                if(prev == '(')r += pow(2, d);
                prev = ')';
            }else{
                d++;
                prev = '(';
            }
        }
        return r;
    }
};