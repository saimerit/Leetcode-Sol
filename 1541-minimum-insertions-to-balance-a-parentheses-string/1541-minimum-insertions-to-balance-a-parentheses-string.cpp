class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(!st.empty() && i+1 < n && s[i+1] == ')'){
                    st.pop();
                    i++;
                }else{
                    if(st.empty()) ans++;
                    else st.pop();
                    if(s[i+1] != ')') ans++;
                    else i++;
                }
                
            }
        }
        ans += st.size()*2;
        return ans;
    }
};