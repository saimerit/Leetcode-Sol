class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> probs(n, 0.0);
        probs[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            int u = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            if(u == end_node) return probs[u];
            if(p < probs[u]) continue;
            for(const auto& v : adj[u]){
                if(probs[v.first] < p * v.second){
                    probs[v.first] = p * v.second;
                    pq.push({probs[v.first], v.first});
                }
            }
        }
        return probs[end_node];
    }
};