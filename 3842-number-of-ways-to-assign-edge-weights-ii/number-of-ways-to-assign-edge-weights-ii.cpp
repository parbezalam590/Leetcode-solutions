class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 17;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;

    void dfs(int node, int parent) {

        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (auto child : adj[node]) {

            if (child == parent)
                continue;

            depth[child] = depth[node] + 1;

            dfs(child, node);
        }
    }

    int lca(int u, int v) {

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {

            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {

            if (up[u][i] != up[v][i]) {

                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        adj.resize(n + 1);

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);

        dfs(1, 0);

        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int edgesInPath = depth[u] + depth[v] - 2 * depth[L];

            if (edgesInPath == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(pow2[edgesInPath - 1]);
            }
        }

        return ans;
    }
};