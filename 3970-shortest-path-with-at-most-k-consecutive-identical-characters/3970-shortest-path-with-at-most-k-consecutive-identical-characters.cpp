class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto & e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        dist[0][1] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto l = pq.top();
            pq.pop();
            
            int w = l[0];
            int no = l[1];
            int s = l[2];

            if (w > dist[no][s]) continue;
            if (no == n - 1) return w;
            for (const auto& nbr : adj[no]) {
                int next_node = nbr.first;
                int edge_weight = nbr.second;

                int ns = (labels[no] != labels[next_node]) ? 1 : (s + 1);

                if (ns > k) continue;

                if (dist[next_node][ns] > w + edge_weight) {
                    dist[next_node][ns] = w + edge_weight;
                    pq.push({w + edge_weight, next_node, ns});
                }
            }
        }
        return -1;
    }
};