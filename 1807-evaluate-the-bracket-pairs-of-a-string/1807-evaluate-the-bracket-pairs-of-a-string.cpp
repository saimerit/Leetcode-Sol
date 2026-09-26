class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string, string> mp;
        for(const auto& e : knowledge){
            mp[e[0]] = e[1];
        }
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                string k = "";
                int j = i+1;
                while(s[j] != ')'){
                    k += s[j];
                    j++;
                }
                ans += (mp.find(k) == mp.end() ? "?" : mp[k]);
                i = j;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};