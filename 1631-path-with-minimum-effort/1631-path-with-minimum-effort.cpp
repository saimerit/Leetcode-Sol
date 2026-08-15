class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i == n-1 && j == m-1) return diff;
            for(int k = 0; k < 4; k++){
                int newr = dr[k] + i;
                int newc = dc[k] + j;
                if(newr >= 0 && newc >= 0 && newr < n && newc < m){
                    int newEffort = max(abs(heights[i][j] - heights[newr][newc]), diff);
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    } 
                }
            }
        }
        return 0;
    }
};