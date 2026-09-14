class Solution {
public:
    int find(int a, vector<int>& par){
        if(par[a] == a) return a;
        return par[a] = find(par[a], par);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> par(1001);
        vector<int> c_a, c_b;
        for(auto e : edges){
            int p = e[0];
            int c = e[1];
            if(par[c] != 0){
                c_b = e;
                c_a = {par[c], c};
            }else{
                par[c] = p;
            }
        }
        for(int i = 0; i < 1001; i++) par[i] = i;
        vector<vector<int>> ans;
        for(auto e : edges){
            if(e == c_b) continue;
            int p = find(e[0], par);
            int c = find(e[1], par);
            if(p == c){
                if(c_a.size() > 0) return c_a;
                else return e;
            }else{
                par[p] = c;
            }
        }
        return c_b;
    }
};