// tc= o(nxn) = sc
int numIslands(vector<vector<char>>& grid) {
        
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    queue<pair<int, int>> Q;

    int ans = 0; 
        
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(!visited[i][j] && grid[i][j]=='1'){
                Q.push({i,j});
                while(!Q.empty()){
                    pair<int, int> it = Q.front();
                    int r = it.first;
                    int s = it.second;
                    visited[r][s] = true;
                    Q.pop();

                    for(int p=r-1; p<=r+1; p++){
                        for(int q=s-1; q<=s+1; q++){
                            if(p>=0 && p<n && q>=0 && q<m){
                                if(!visited[p][q] && grid[p][q]=='1'){
                                    Q.push({p,q});
                                }
                            visited[p][q] = true;
                            }
                        }
                    }

                }
                
                ans++;
            }
                
        }
    }
    
    return ans;
        
}
