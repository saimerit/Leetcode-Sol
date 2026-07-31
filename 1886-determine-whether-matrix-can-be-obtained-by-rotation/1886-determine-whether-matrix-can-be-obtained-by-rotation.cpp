class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        int k = 0;
        while(k < n){
            reverse(mat[k].begin(), mat[k].end());
            k++;
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        if(mat == tar) return true;
        for(int i = 0; i <= 3; i++){
            rotate(mat);
            if(mat == tar) return true;
        }
        return false;
    }
};