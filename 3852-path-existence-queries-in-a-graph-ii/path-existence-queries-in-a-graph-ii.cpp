class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n), val(n);

        for(int i = 0; i < n; i++) {
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }

        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;

        for(int i = 1; i < n; i++) {
            if(val[i] - val[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        vector<int> R(n);

        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && val[j + 1] - val[i] <= maxDiff)
                j++;
            R[i] = j;
        }

        int LOG = 1;
        while((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = R[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            if(u > v)
                swap(u, v);

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int dist = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v && up[k][cur] > cur) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};