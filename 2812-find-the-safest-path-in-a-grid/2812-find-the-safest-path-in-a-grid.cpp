class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         int n = grid.size();

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){

        auto cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;

        for(auto d:dir){

            int nx=x+d.first;
            int ny=y+d.second;

            if(nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny]==INT_MAX){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    int low=0,high=2*n,ans=0;

    while(low<=high){

        int mid=low+(high-low)/2;

        if(dist[0][0]<mid){
            high=mid-1;
            continue;
        }

        queue<pair<int,int>> bfs;
        vector<vector<int>> vis(n,vector<int>(n,0));

        bfs.push({0,0});
        vis[0][0]=1;

        bool ok=false;

        while(!bfs.empty()){

            auto cur=bfs.front();
            bfs.pop();

            int x=cur.first;
            int y=cur.second;

            if(x==n-1 && y==n-1){
                ok=true;
                break;
            }

            for(auto d:dir){

                int nx=x+d.first;
                int ny=y+d.second;

                if(nx>=0 && ny>=0 && nx<n && ny<n &&
                   !vis[nx][ny] && dist[nx][ny]>=mid){

                    vis[nx][ny]=1;
                    bfs.push({nx,ny});
                }
            }
        }

        if(ok){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
    }
};