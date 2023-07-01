// sc = nxm + nxm   tc = nxm + 4xnxm
int orangesRotting(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> Q;
    int visited[n][m];
    int cntFresh = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2)
            {
                visited[i][j] = 2;
                Q.push({ {i,j}, 0 });
            }
            else
            visited[i][j] = 0;

            if (grid[i][j]==1) cntFresh++;
        }
    }

    int count = 0;
    int totTime = 0;
    while(!Q.empty()){
        auto it = Q.front();
        int r = it.first.first;
        int s = it.first.second;
        int t = it.second;
        totTime = max(totTime,t);
        Q.pop();

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        for(int i=0; i<4; i++){
            int p = r + delRow[i];
            int q = s + delCol[i];
            if( p>=0 && p<n && q>=0 && q<m && visited[p][q]!=2 && grid[p][q]==1 ){
                visited[p][q] = 2;
                Q.push({{p,q},t+1});
                count++;
            }
        }
    }

    if(count != cntFresh) return -1;
    return totTime;
}