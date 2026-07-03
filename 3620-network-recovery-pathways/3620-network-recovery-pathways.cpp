class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        long long high = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            high = max(high, 1LL * e[2]);
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto& p : adj[u]) {
                if (--indegree[p.first] == 0)
                    q.push(p.first);
            }
        }

        auto check = [&](long long limit) {
            const long long INF = 4e18;
            vector<long long> dp(n, INF);
            dp[0] = 0;

            for (int u : topo) {

                if (dp[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto& p : adj[u]) {

                    int v = p.first;
                    int w = p.second;

                    if (w < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    if (dp[u] + w < dp[v])
                        dp[v] = dp[u] + w;
                }
            }

            return dp[n - 1] <= k;
        };

        long long low = 0, ans = -1;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};