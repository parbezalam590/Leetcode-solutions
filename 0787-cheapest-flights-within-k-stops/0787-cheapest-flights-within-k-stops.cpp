class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int  wt = it[2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        
        dist[src] = 0;
        q.push({0,{src,0}});
        
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops > k) continue;
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edW  = it.second;
                
                if(cost + edW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1 , {adjNode , cost + edW}});
                }
                
            }
        }
        if(dist[dst] == 1e9)  return -1;
        return dist[dst];
    }
};