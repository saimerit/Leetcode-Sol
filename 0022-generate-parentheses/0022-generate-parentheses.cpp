class Solution {
public:
    void f(int start, string curr, vector<string>& ans, int n, int depth){
        if(depth < 0) return;
        if(start == n*2){
            if(depth == 0) ans.push_back(curr);
            return;
        }
        f(start + 1, curr + "(", ans, n, depth +1);
        f(start + 1, curr + ")", ans, n, depth -1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string c = "";
        f(0, c, ans, n, 0);
        return ans;
    }
};