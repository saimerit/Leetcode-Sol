class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0, cl = 0;
        for (char c : s){
            op += (c=='(');
            (op >0)?op -= (c==')'):cl += (c == ')');
        }
        return op + cl;   
    }
};