class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& i : times){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u-1].push_back({v-1, w});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k-1] = 0;
        pq.push({0, k-1});
        
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[u]) continue;
            for(const auto& e : adj[u]){
                int v = e.first;
                int weight = e.second;
                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int m = 0;
        for(int i : dist){
            if(i == 2147483647) return -1;
            if(m < i) m = i;
        }
        return m;
    }
};