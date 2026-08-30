class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<bool> inMst(n, false);
        int mstCost = 0;
        while(pq.size() > 0){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if(inMst[u]) continue;
            inMst[u] = true;
            mstCost += w;
            for(int i= 0; i < n; i++){
                if(!inMst[i]){
                    pq.push({manDist(points, u, i), i});
                }
            }
        }
        return mstCost;
    }
};