class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++){
            if(col[i] != -1) continue;
            col[i] = 0;
            q.push(i);  
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : graph[u]){
                    if(col[v] == -1){
                        col[v] = 1 - col[u];
                        q.push(v);
                    }else if(col[v] == col[u]) return false;
                }
            }
        }
        return true;
    }
};