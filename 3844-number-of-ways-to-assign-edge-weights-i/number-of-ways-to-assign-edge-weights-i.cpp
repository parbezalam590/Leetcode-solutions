class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> depth(n + 1, -1);
    queue<int> q;

    q.push(1);
    depth[1] = 0;

    int mxDepth = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                mxDepth = max(mxDepth, depth[v]);
                q.push(v);
            }
        }
    }

    long long ans = 1;
    long long base = 2;
    int power = mxDepth - 1;

    while (power > 0) {
        if (power & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        power >>= 1;
    }

    return (int)ans;
    }
};