
bool searchMatrix(vector<vector<int>>& mat, int target) {

    int n = mat.size();
    int m = mat[0].size();

    int row = n-1;

    for ( int  i = 0; i< n-1; i++) {
        if(target < mat[i+1][0]) {
            row = i;
        }
    }

    return binary_search(mat[row].begin(), mat[row].end(), target);
}