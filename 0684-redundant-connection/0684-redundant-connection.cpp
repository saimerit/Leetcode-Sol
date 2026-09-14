class Solution {
public:
    int find(int u, vector<int>& par){
        if(par[u] == u) return u;
        return par[u] = find(par[u], par);
    }
    void unionByRank(int a, int b, vector<int>& par, vector<int>& rank, vector<vector<int>>& ans){
        int parA = find(a, par);
        int parB = find(b, par);
        if(parA == parB) ans.push_back({a, b});
        else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par(1001);
        vector<int> rank(1001, 0);
        vector<vector<int>> ans;
        for(int i =0 ; i < 1001; i++) par[i] = i;
        for(auto it : edges){
            unionByRank(it[0], it[1], par, rank, ans);
        }
        return ans[0];
    }
};