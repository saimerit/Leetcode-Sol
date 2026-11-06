class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // unordered_map<int, vector<int>> mp;
        // for(int i = 0; i < logs.size(); i++) {
        //     mp[logs[i][1]].push_back(logs[i][0]);
        // }
        // vector<int> ans;
        // for(int q : queries){
        //     vector<bool> rec(n+1, false); 
        //     for(int i = q-x; i <= q; i++){
        //         for(int ser : mp[i]){
        //             rec[ser] = true;
        //         }
        //     }
        //     int cnt = -1;
        //     for(bool noreq : rec) if(!noreq) cnt++;
        //     ans.push_back(cnt);
        // }
        // return ans;
        int m = queries.size();
        int num_logs = logs.size();
        vector<int> ans(m);

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> server_count(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;

        for (int i = 0; i < m; ++i) {
            int q_time = sorted_queries[i].first;
            int orig_idx = sorted_queries[i].second;

            int window_start = q_time - x;
            int window_end = q_time;

            while (right < num_logs && logs[right][1] <= window_end) {
                int s_id = logs[right][0];
                if (server_count[s_id] == 0) {
                    active_servers++;
                }
                server_count[s_id]++;
                right++;
            }

            while (left < num_logs && logs[left][1] < window_start) {
                int s_id = logs[left][0];
                server_count[s_id]--;
                if (server_count[s_id] == 0) {
                    active_servers--;
                }
                left++;
            }

            ans[orig_idx] = n - active_servers;
        }

        return ans;
    }
};