class Solution {
public:
    void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int es = connections.size();
        if(es < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto const& e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int cc = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                cc++;
            }
        }
        return cc-1;
    }
};