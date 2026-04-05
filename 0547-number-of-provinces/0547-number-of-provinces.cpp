class Solution {
public:
    void BFS(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int neigh = q.front();
            q.pop();

            for (auto it : adj[neigh]) {
                if (!visited[it]) {
                    q.push(it);          // OR simply BFS(adj, visited , it )
                    visited[it] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                BFS(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};