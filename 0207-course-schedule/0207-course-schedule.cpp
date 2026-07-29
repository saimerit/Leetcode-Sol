class Solution {
public:
    bool dfs(int u, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& adj){
        vis[u] = true;
        recPath[u] = true;
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(v, vis, recPath, adj)) return true;
            }else if(recPath[v]) return true;
        }
        recPath[u] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> recPath(V, false);
        vector<bool> vis(V, false);
        
        for(vector<int> f : edges){
            adj[f[0]].push_back(f[1]);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, recPath, adj)) return false;
            }
        }
        return true;
    }
};