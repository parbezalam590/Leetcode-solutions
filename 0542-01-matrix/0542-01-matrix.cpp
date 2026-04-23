class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        queue<pair<pair<int, int>, int>> q;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                } else {
                    visited[i][j] = false;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();
            ans[row][col] = steps;

            for (int d = 0; d < 4; d++) {
                int nrow = row + delRow[d];
                int ncol = col + delCol[d];

                if (nrow >= 0 && ncol >= 0 && nrow < r && ncol < c &&
                    !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, steps+1});
                    visited[nrow][ncol] = true;
                }
            }
        }
            return ans;
        }
    };