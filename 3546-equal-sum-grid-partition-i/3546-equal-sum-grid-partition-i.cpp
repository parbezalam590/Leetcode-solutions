class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        long long total = 0LL;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                total += grid[i][j];
            }
        }

        long long rowSum = 0LL;
         for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                rowSum += grid[i][j];
            }
            if ((total - rowSum) == rowSum)
                return true;
        }
        long long columnSum = 0LL;
        for (int j = 0; j < c - 1 ; j++) {
            for (int i = 0; i < r ; i++) {
                columnSum += grid[i][j];
            }
            if ((total - columnSum) == columnSum)
                return true;
        }

        return false;
    }
};