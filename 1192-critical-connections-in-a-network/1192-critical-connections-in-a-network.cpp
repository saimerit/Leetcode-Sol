#include <algorithm>
class Solution {
public:
    void dfs(int u, vector<bool>& vis, int parU, vector<vector<int>>& store, vector<vector<int>>& adj, vector<int>& dt, vector<int>& low, int& time){
        vis[u] = true;
        dt[u] = low[u] = ++time;
        for(int v : adj[u]){
            if(v == parU) continue;
            if(!vis[v]){
                dfs(v, vis, u, store, adj, dt, low, time);
                low[u] = min(low[u], low[v]);
                if(low[v] > dt[u]){
                    store.push_back({u, v});
                }
            }else if(v != parU){
                    low[u] = min(low[u], dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> dt(n, 0);
        vector<int> low(n, 0);
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        vector<vector<int>> ans;
        int time = 0;
        for(auto const& c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        dfs(0, vis, -1, ans, adj, dt, low, time);
        return ans;
    }
};