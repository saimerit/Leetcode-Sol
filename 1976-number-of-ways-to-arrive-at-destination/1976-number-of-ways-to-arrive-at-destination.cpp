class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& e: roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int mod = (int)(1e9 + 7);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(const auto& ne : adj[node]){
                int v = ne.first;
                long long d = ne.second;
                if(dis + d < dist[v]){
                    dist[v] = dis + d;
                    pq.push({dist[v], v});
                    ways[v] = ways[node];
                }else if(dis + d == dist[v]){
                    ways[v] = (ways[v] + ways[node])%mod;
                }
            }
        }
        return (int)(ways[n-1]%mod);
    }
};