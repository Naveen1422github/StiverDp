int mod = 1e9 + 7;
int minSumPath(vector<vector<int>> &grid) {

   int m = grid.size();
   int n = grid[0].size();

   vector<vector<int>>dp(m,vector<int>(n,-1));

   for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
        if(i==0 && j==0) dp[0][0] = grid[0][0];
        else{
            int down = mod;
            int right = mod;

            if(j>0)
            down = grid[i][j] + dp[i][j-1];
            if(i>0)
            right = grid[i][j] + dp[i-1][j];
            
            dp[i][j] = min(down, right);
        }
    }
   }

   return dp[m-1][n-1];
}