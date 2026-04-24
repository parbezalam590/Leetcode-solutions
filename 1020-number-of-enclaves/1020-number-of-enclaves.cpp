class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<int>>& grid, int delRow[], int delCol[]) {
        visited[row][col] = 1;
        int r = grid.size();
        int c = grid[0].size();

        for (int d = 0; d < 4; d++) {
            int nrow = row + delRow[d];
            int ncol = col + delCol[d];

            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, visited, grid, delRow, delCol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vector<vector<int>> visited(r, vector<int>(c, 0));

        // first /last row
        for (int i = 0; i < c; i++) {
            // first row
            if (!visited[0][i] && grid[0][i] == 1) {
                dfs(0, i, visited, grid, delRow, delCol);
            }
            // last row
            if (!visited[r - 1][i] && grid[r - 1][i] == 1) {
                dfs(r - 1, i, visited, grid, delRow, delCol);
            }
        }

        // first /last column
        for (int j = 0; j < r; j++) {
            // first column
            if (!visited[j][0] && grid[j][0] == 1) {
                dfs(j, 0, visited, grid, delRow, delCol);
            }
            // last column
            if (!visited[j][c - 1] && grid[j][c - 1] == 1) {
                dfs(j, c - 1, visited, grid, delRow, delCol);
            }
        }

        // cnt to store the number of ones that cant be walked
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};