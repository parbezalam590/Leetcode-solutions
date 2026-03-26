class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course); // b → a
        }
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int v : adj[i]) {
                inDegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbour : adj[node]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        if (result.size() != n) return {};

        return result;
    }
};