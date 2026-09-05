class Solution {
public:
    int findPar(int x, vector<int>& par) {
        if (par[x] == x) return x;
        return par[x] = findPar(par[x], par);
    }

    void unionBySize(int x, int y, vector<int>& par, vector<int>& size) {
        int v_x = findPar(x, par);
        int v_y = findPar(y, par);
        if (v_x == v_y) return;
        
        if (size[v_x] < size[v_y]) {
            par[v_x] = v_y;
            size[v_y] += size[v_x];
        } else {
            par[v_y] = v_x;
            size[v_x] += size[v_y];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        unordered_map<string, int> m;
        vector<int> par(n);
        vector<int> size(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < details[i].size(); j++){
                if(m.find(details[i][j]) == m.end()){
                    m[details[i][j]] = i;
                }else{
                    unionBySize(i, m[details[i][j]], par, size);
                }
            }
        }
        vector<vector<string>> mailmerge(n);
        for(auto it : m){
            string mail = it.first;
            int node = findPar(it.second, par);
            mailmerge[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mailmerge[i].size() == 0) continue;
            sort(mailmerge[i].begin(), mailmerge[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(const auto& it : mailmerge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};