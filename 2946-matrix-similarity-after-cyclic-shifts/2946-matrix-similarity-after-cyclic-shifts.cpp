class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
         int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> temp = mat;
        vector<vector<int>> org = mat;
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i % 2 == 0) {
                        temp[i][j] = mat[i][((j - 1) + c) % c];
                    } else {
                        temp[i][j] = mat[i][((j + 1) + c) % c];
                    }
                }
                mat = temp;
            }
        }
        return mat == org;
        
    }
};