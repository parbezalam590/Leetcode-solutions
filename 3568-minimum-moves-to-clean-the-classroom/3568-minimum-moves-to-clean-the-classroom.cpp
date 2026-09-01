class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
         int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int maskSize = 1 << cnt;
        int fullMask = maskSize - 1;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(maskSize, -1))
        );

        queue<array<int, 5>> q;

        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, mask, en, dist] = q.front();
            q.pop();

            if (mask == fullMask)
                return dist;

            if (en == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int newEnergy = en - 1;
                int newMask = mask;

                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << id[nr][nc]);
                }

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (best[nr][nc][newMask] >= newEnergy)
                    continue;

                best[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    dist + 1
                });
            }
        }

        return -1;
    }
};