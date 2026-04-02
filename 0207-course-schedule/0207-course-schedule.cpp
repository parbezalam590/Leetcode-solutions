class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        for(auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];

            adj[v].push_back(u);
        }

        vector<int> inDegree(V,0); 
        
        for(int i = 0 ; i < V ; i++) {
            for(int &v : adj[i]) {
                inDegree[v]++;
            }
        }
        queue<int> q;
        int count = 0;
        for(int i = 0 ; i < V ; i++) {
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
        if(count == V)  {
            return true;
    }
    return false;
    } 
};