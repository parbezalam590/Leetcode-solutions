class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // making adj matrix
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0; // as the node with itself has dist as 0
        }

        // now for the rest of the entries in adj matrix through input edges
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            matrix[u][v] = wt;
            matrix[v][u] = wt; // as undirected
        }
        // start flyodd warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // so that no unnecessary updates happen
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                        matrix[i][j] =
                            min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        // after getting shortest distance matrix ..
        // we will now traverse through the matrix to count the elemnts <=
        // disthreshold
        int ansCity;          // return the city
        int mincnt = INT_MAX; // keep track of min cnt

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j &&
                    matrix[i][j] <=
                        distanceThreshold) { // i!=j as we dont need same city
                                             // like city 0 -> city 0
                    cnt++;
                }
            }

            if (cnt <= mincnt) {
                mincnt = cnt;
                ansCity = i;
            }
        }
        return ansCity;
    }
};