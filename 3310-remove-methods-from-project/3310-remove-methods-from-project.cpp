class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<bool>& vis){
        vis[curr] = true;
        for(int v : adj[curr]){
            if(!vis[v]) dfs(v, adj, vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ind(n);
        for(vector<int> l : invocations){
            adj[l[0]].push_back(l[1]);
            ind[l[1]].push_back(l[0]);
        }
        vector<bool> vis(n, false);
        dfs(k, adj, vis);
        vector<int> res;
        vector<int> res1;
        for(int i = 0; i < n; i++) res1.push_back(i);
        for(int i = 0; i < n; i++){
            if(vis[i]){
                for(int j : ind[i]){
                    if(!vis[j]){
                        return res1;
                    }
                }
            }else{
                res.push_back(i);
            }
        }
        return res;
    }
};