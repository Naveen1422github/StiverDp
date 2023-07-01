// sc = nxm   tc = nxmxlog(set(len)) + nxmx4 = nxmxlog(nxm) + nxmx4

void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int x, int y, vector<pair<int,int>> &vec, int bx, int by){
    
    int n = grid.size();
    int m = grid[0].size();    
    
    vis[x][y] = true;
    vec.push_back({x-bx,y-by});

    int row[] = {1, 0, -1, 0};
    int col[] = {0, 1, 0, -1};
        
    for(int i=0; i<4; i++){
        int r = x + row[i];
        int s = y + col[i];
        if(r>=0 && s>=0 && r<n && s<m && grid[r][s] == 1 && !vis[r][s]){
            dfs(grid, vis, r, s, vec, bx, by);
        }
    }

}
int countDistinctIslands(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool> (m, false));

    set<vector<pair<int, int>>> st;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>> vec;
                dfs(grid, vis, i, j, vec, i, j);
                st.insert(vec);
            }
        }
    }

    return st.size();
}