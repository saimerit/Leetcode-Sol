class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> out;
        stack<char> in;
        int d = 0;
        string ans = "";
        for(char i : s){
            if(i == '('){
                if(!out.empty()){
                    in.push(i);
                    d++;
                    ans.push_back('(');
                }else{
                    out.push(i);
                    d++;
                }
            }else{
                if(!in.empty() && d > 1 && in.top() == '('){
                    in.pop();
                    d--;
                    ans.push_back(')');
                }else{
                    out.pop();
                    d--;
                }
            }
        }
        return ans;
    }
};