void dfs(vector<vector<int>> &grid, vector<vector<bool>>&vis, int x, int y ){

    int n = grid.size();
    int m = grid[0].size();
    vis[x][y] = true;

    int row[] = {1, 0, -1, 0};
    int col[] = {0, 1, 0, -1};
        
    for(int i=0; i<4; i++){
        int r = x + row[i];
        int s = y + col[i];
        if(r>=0 && s>=0 && r<n && s<m && grid[r][s] == 1 && !vis[r][s]){
            dfs(grid, vis, r, s);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis (n, vector<bool>(m, false));


    for(int i=0; i<n; i++){
        if(grid[i][0]==1 && !vis[i][0]){
            dfs(grid,vis,i,0);
        }
        if(grid[i][m-1]==1  && !vis[i][m-1]){
            dfs(grid,vis,i,m-1);
        }
    }

    for(int j=1; j<m-1; j++){
        if(grid[0][j]==1 && !vis[0][j]){
            dfs(grid,vis,0,j );
        }
        if(grid[n-1][j]==1 && !vis[n-1][j]){
            dfs(grid,vis,n-1,j);
        }
    }

    int ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && !vis[i][j])
            ans++;
        }
    }

    return ans;
}