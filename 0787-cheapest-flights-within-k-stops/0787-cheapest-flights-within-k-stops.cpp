class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> stops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src, 0});
        while(!q.empty()){
            int p = q.top()[0];
            int u = q.top()[1];
            int l = q.top()[2];
            q.pop();
            if(u == dst) return p;
            if(l > stops[u] || l > k ) continue;
            stops[u] = l;
            for(const auto& v : adj[u]){
                q.push({p + v.second, v.first, l+1});
            }
        }
        return -1;
    }
};