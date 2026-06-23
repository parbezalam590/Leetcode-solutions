class Solution {
public:
    const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int sz = r - l + 1;

    vector<long long> dpUp(sz, 0), dpDown(sz, 0);
    vector<long long> ndpUp(sz, 0), ndpDown(sz, 0);
    vector<long long> prefixUp(sz + 1, 0), prefixDown(sz + 1, 0);

    for (int v = 0; v < sz; v++) {
        dpUp[v]   = v;
        dpDown[v] = sz - 1 - v;
    }

    for (int step = 3; step <= n; step++) {
        prefixUp[0] = prefixDown[0] = 0;
        for (int v = 0; v < sz; v++) {
            prefixUp[v + 1]   = (prefixUp[v]   + dpUp[v])   % MOD;
            prefixDown[v + 1] = (prefixDown[v] + dpDown[v]) % MOD;
        }

        long long totalUp = prefixUp[sz];

        for (int v = 0; v < sz; v++) {
            ndpUp[v]   = prefixDown[v];
            ndpDown[v] = (totalUp - prefixUp[v + 1] + MOD) % MOD;
        }

        swap(dpUp,   ndpUp);
        swap(dpDown, ndpDown);
    }

    long long ans = 0;
    for (int v = 0; v < sz; v++) {
        ans = (ans + dpUp[v] + dpDown[v]) % MOD;
    }

    return (int)ans;
    }
};