vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<char>> vis (n, vector<char>(m, 'X'));
    
    vector<vector<bool>> v (n, vector<bool> (m, false));

    queue<pair<int, int>> q;

    for(int j=0; j<m; j++){
        if(mat[0][j] == 'O')
        {
            q.push({0,j});
        }
        if(mat[n-1][j]=='O')
            q.push({n-1,j});
    }

    for(int i=1; i<n-1; i++){
        if(mat[i][0]=='O')
        q.push({i,0});
        if(mat[i][m-1]=='O')
        q.push({i,m-1});
    }



    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        vis[x][y] = 'O';
        v[x][y] = true;
        q.pop();

        int row[] = {1, 0, -1, 0};
        int col[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int r = x + row[i];
            int s = y + col[i];
            if(r>=0 && s>=0 && r<n && s<m && mat[r][s] == 'O' && !v[r][s]){
                q.push({r,s});
            }
        }
    }
    return vis;
}