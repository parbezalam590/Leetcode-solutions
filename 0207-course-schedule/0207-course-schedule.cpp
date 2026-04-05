class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        for(auto &e : prerequisites) {
            int v = e[0];
            int u = e[1];
            adj[u].push_back(v);
        }

        vector<int> inDegree(n , 0);
        for(int i = 0 ; i < n ; i++) {
            for(int &v : adj[i] ) {
                inDegree[v]++;
            }
        }
        queue<int> q;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int &v : adj[node]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == n) {
            return true;
        }
        return false;
    }
};