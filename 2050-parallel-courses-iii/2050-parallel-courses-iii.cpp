class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> ind(n);
        for(vector<int> l : relations){
            adj[l[0]-1].push_back(l[1]-1);
            ind[l[1]-1]++;
        }
        for(int i = 0; i < n; i++){
            if(ind[i] == 0) q.push(i);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = time[i];
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            for(int k : adj[curr]){
                ans[k] = max(ans[k], ans[curr] + time[k]);
                ind[k]--;
                if(ind[k] == 0) q.push(k);
            }
        }
        int fans = 0;
        for(int i = 0; i < n; i++){
            if(fans < ans[i]) fans = ans[i];
        }
        return fans;
    }
};