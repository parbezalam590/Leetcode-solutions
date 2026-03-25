class Solution {
public:
    void rotate(vector<vector<int>>mat, vector<vector<int>>&temp, int r, int c) 
    {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                temp[j][r-1-i] = mat[i][j];
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>>temp= mat;

        for (int i = 0; i < 4; i++) {
            if (temp == target)
                return true;
            rotate(temp , temp, r, c);

        }
        //rotate(mat, temp,r ,c);

        return false;
    }
};