class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        if(s.length() % 2 != 0) return false;
        stack<char> st;
        for(char i : s){
            if(mp.find(i) != mp.end()){
                if(st.empty() || mp[i] != st.top()) return false;
                st.pop();
            }else{
                st.push(i);
            }
        }
        return st.empty();
    }
};