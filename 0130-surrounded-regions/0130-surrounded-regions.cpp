class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board , int delRow[] , int delCol[]) {
        visited[row][col] = 1;
        int r = board.size();
        int c = board[0].size();

        // traverse in 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board, delRow, delCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // visited matrix to store all visited O's
        vector<vector<int>> visited(r, vector<int>(c, 0));

        // now lets travers first and last row
        for (int i = 0; i < c; i++) {
            if (!visited[0][i] && board[0][i] == 'O') {
                dfs(0, i, visited, board, delRow, delCol);
            }

            // last row
            if (!visited[r - 1][i] && board[r - 1][i] == 'O') {
                dfs(r - 1, i, visited, board, delRow, delCol);
            }
        }
        // first column
        for (int j = 0; j < r; j++) {
            if (!visited[j][0] && board[j][0] == 'O') {
                dfs(j, 0, visited, board, delRow, delCol);
            }

            // last colum
            if (!visited[j][c - 1] && board[j][c - 1] == 'O') {
                dfs(j, c - 1, visited, board, delRow, delCol);
            }
        }
        // now we to covert all Os to X which is not visited and mat[i][j] = O;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};