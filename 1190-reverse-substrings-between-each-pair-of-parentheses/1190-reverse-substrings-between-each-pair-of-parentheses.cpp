class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.length();
        string store = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                store = "";
                while(st.top() != '('){
                    store += st.top();
                    st.pop(); 
                }
                st.pop();
                if(!st.empty() || i != n-1){
                    for(int j = 0; j < store.length(); j++){
                        st.push(store[j]);
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            store = "";
            while(!st.empty()){
                store = st.top() + store;
                st.pop();
            }
        }
        return store;
    }
};