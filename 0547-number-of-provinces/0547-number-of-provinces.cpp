class Solution {
public:
    void DFS(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                DFS(adj, visited, it);
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
                    DFS(adj, visited, i);
                    cnt++;
                }
        }
        return cnt;
    }
};