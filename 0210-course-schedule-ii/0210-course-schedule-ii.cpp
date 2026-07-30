class Solution {
public:
    bool dfs(int u, vector<bool>& vis, vector<vector<int>>& pre, stack<int>& s, vector<bool>& rec){
        vis[u] = true;
        rec[u] = true;
        for(int i : pre[u]){
            if(!vis[i]){
                if(dfs(i, vis, pre, s, rec)) return true;
            }else if(rec[i]){
                return true;
            }
        }
        rec[u] = false;
        s.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        stack<int> st;
        vector<bool> recPath(numCourses, false);
        vector<bool> vis(numCourses, false);
        for(vector<int> l : prerequisites){
            adj[l[0]].push_back(l[1]);
        }
        bool con = true;
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, st, recPath)) con = false;
            }
        }
        vector<int> ans;
        while(!st.empty() && con == true){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};