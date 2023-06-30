


int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool> (m, false));

    queue<pair<int, int>> Q;

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==2 && !visited[i][j])
            {
                Q.push({i,j});
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
                        if( p>=0 && p<n && q>=0 && q<m && !visited[p][q] && grid[p][q]==1 ){
                            grid[p][q] = 2;
                            Q.push({p,q});
                        }
                    }
                }

                ans++;
            }
        }
    } 

    return ans;
}