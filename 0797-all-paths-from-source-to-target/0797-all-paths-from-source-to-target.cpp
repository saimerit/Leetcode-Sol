class Solution {
public:
    void f(int u, vector<vector<int>>& adj, vector<int> path, vector<vector<int>>& ans, int n){
        if(u==n){
            path.push_back(u);
            ans.push_back(path);
            return;
        }
        if(!adj[u].empty()){
            path.push_back(u);
            for(int v : adj[u]){
                f(v, adj, path, ans, n);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> path;
        f(0, graph, path, ans, n-1);
        return ans;
    }
};