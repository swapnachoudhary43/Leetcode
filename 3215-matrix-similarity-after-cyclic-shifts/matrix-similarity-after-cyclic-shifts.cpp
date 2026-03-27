class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        int shift = k % n;  // effective shift
        
        vector<vector<int>> result = mat;
        
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                // even row -> left shift
                rotate(result[i].begin(), result[i].begin() + shift, result[i].end());
            } else {
                // odd row -> right shift
                rotate(result[i].begin(), result[i].end() - shift, result[i].end());
            }
        }
        
        return result == mat;
    }
};