//chutiya kata it is no of islands
#include<bits/stdc++.h>

void dfs(int** arr,int n, int m, vector<vector<bool>> &vis, int x, int y){
    
    vis[x][y] = true;

    for(int r=x-1; r<=x+1; r++){
    for(int s=y-1; s<=y+1; s++){
      if (r >= 0 && s >= 0 && r < n && s < m && arr[r][s] == 1 && !vis[r][s]) {
        dfs(arr, n, m, vis, r, s);
      }
    }
    }
}

int getTotalIslands(int** arr, int n, int m){
    vector<vector<bool>> vis(n, vector<bool> (m, false));

    int ans=0;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && arr[i][j]==1){
                dfs(arr, n, m, vis, i, j);  
                ans++;
            }
        }
    }

    return ans;
}
