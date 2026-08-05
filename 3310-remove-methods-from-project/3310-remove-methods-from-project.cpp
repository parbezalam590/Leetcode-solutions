class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n,0);
        vector<bool> suspicious(n,false);

        for(auto edges : invocations ) {
            int u = edges[0];
            int v = edges[1];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int &ngbr : adj[curr]) {
                inDeg[ngbr]--;

                if(!suspicious[ngbr]) {
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for(int i = 0 ; i < n ; i++) {
            if(suspicious[i]  && inDeg[i] > 0) {
                cannotRemove = true;
                break;
            }
    if(!suspicious[i]) {
        result.push_back(i);
    }
        }

        if(cannotRemove) {
            vector<int> vec(n);
            for(int i = 0 ; i < n ; i++) {
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};