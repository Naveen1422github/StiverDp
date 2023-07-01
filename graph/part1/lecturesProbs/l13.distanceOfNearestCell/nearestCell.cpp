// tc = nxm + nxmx4  sc = nxm
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dis (n, vector<int>(m, 0));
    vector<vector<int>> vis (n, vector<int>(m, 0));

    queue<pair<pair<int, int> ,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                vis[i][j] = 1;
                q.push({{i,j}, 0});
            }
            else
                vis[i][j] = 0;
        }
    }


    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;

        dis[x][y] = d;

        q.pop();

        int row[] = {1, 0, -1, 0};
        int col[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int r = x + row[i];
            int s = y + col[i];
            if(r>=0 && s>=0 && r<n && s<m && vis[r][s] == 0){
                q.push({{r,s}, d+1});
                vis[r][s] = 1;
            }
        }
    }
    return dis;
}