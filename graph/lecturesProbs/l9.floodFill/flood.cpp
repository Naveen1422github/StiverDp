
// tc = o(4xnxm) sc = o(nxm) + o(nxm)

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    queue<pair<int, int>> Q;

    Q.push({sr,sc});
    int preColor = image[sr][sc];
    image[sr][sc] = newColor;
        
    while(!Q.empty()){
        pair<int, int> it = Q.front();
        int r = it.first;
        int s = it.second;
        visited[r][s] = true;
        Q.pop();



        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        for(int i=0; i<4; i++){
            int p = r + delRow[i];
            int q = s + delCol[i];
            if( p>=0 && p<n && q>=0 && q<m && !visited[p][q] && image[p][q]==preColor ){
                image[p][q] = newColor;
                Q.push({p,q});
            }
        }
    }

    return image;
}