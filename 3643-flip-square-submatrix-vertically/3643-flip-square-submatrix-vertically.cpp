class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> temp = grid;
        for(int i = 0 ; i < k ; i++) {
            for(int j = 0 ; j < k ; j++) {
                grid[x+i][y+j] = temp[x+(k-i-1)][y+j];
            }
        }
        return grid;
    }
};