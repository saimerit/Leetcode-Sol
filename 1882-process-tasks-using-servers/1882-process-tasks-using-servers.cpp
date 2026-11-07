class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Min-heap for free servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        // Min-heap for busy servers: {free_time, weight, index}
        using BusyEntry = tuple<long long, int, int>;
        priority_queue<BusyEntry, vector<BusyEntry>, greater<BusyEntry>> busy_servers;

        vector<int> ans(m);
        long long cur_time = 0;

        for (int j = 0; j < m; ++j) {
            cur_time = max(cur_time, (long long)j);

            if (free_servers.empty()) {
                cur_time = max(cur_time, get<0>(busy_servers.top()));
            }

            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= cur_time) {
                auto [time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, idx});
            }
            auto [weight, idx] = free_servers.top();
            free_servers.pop();

            ans[j] = idx;
            busy_servers.push({cur_time + tasks[j], weight, idx});
        }

        return ans;
    }
};