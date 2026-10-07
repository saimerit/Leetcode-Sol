class Solution {
public:
    void f(int i, string& curr, int d, string& s, unordered_set<string>& res){
        if(d < 0) return; 
        
        if(i == s.length()){
            if (d == 0) {
                res.insert(curr);
            }
            return;
        }
        
        if(s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            f(i+1, curr, d, s, res);
            curr.pop_back(); 
        }
        else {
            curr.push_back(s[i]);
            f(i+1, curr, d + (s[i] == '(' ? 1 : -1), s, res);
            curr.pop_back(); 
            
            f(i+1, curr, d, s, res);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res; 
        string c;
        f(0, c, 0, s, res);
        
        int m = 0;
        for(const string& ch : res){
            if(ch.length() > m) m = ch.length();
        }
        
        vector<string> k;
        for(const string& ch : res){
            if(ch.length() == m) k.push_back(ch);
        }
        return k;
    }
};