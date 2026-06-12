class Solution {
public:
    const int MOD = 1e9 + 7;

    typedef long long ll;
    ll power(ll base, ll exponent) {
        if (exponent == 0) {
            return 1;
        }
        ll half = power(base, exponent / 2);
        ll result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node,
                    int parent) {
        int depth = 0;
        for (int ngbr : adj[node]) {
            if (ngbr == parent)
                continue;
            depth = max(depth, getMaxDepth(adj, ngbr, node) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int d = getMaxDepth(adj, 1, -1);

        return power(2, d - 1);
    }
        // vector<int> depth(n + 1, -1);
        // queue<int> q;

        // q.push(1);
        // depth[1] = 0;

        // int mxDepth = 0;

        // while (!q.empty()) {
        //     int u = q.front();
        //     q.pop();

        //     for (int v : adj[u]) {
        //         if (depth[v] == -1) {
        //             depth[v] = depth[u] + 1;
        //             mxDepth = max(mxDepth, depth[v]);
        //             q.push(v);
        //         }
        //     }
        // }

        // long long ans = 1;
        // long long base = 2;
        // int power = mxDepth - 1;

        // while (power > 0) {
        //     if (power & 1)
        //         ans = (ans * base) % MOD;

        //     base = (base * base) % MOD;
        //     power >>= 1;
        // }

        // return (int)ans;
        // }
    };