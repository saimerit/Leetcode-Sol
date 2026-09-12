class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revg(n);
        vector<int> ind(n);
        for(int i = 0; i < n; i++){
            for(int v : graph[i]){
                revg[v].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(ind[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v : revg[u]){
                ind[v]--;
                if(ind[v] == 0) q.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};