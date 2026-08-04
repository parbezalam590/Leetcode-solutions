class Solution {
public:

    int t[501][501];
    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int take_i = piles[i] - solve(i+1, j, piles);
        int take_j = piles[j] - solve(i, j - 1, piles);

        return t[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t , -1 , sizeof(t));
        return solve(0, n - 1, piles) >= 0;
    }
};