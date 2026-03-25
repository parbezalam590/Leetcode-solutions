class Solution {
public:



    void rotateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        vector<vector<int>> temp(r,vector<int>(r));
        for(int i = 0 ; i < r ; i++) {
            for(int j = 0 ; j < r ; j++) {
                temp[i][j] = mat[j][r-1-i];
            }
        }
        mat = temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int r = mat.size();

        for(int i = 0 ; i < 4 ; i++) {
            if(mat == target) return true;
        rotateMatrix(mat);   
        }
        return false;
    }
};