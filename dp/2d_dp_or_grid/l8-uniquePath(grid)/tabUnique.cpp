// tc=o(m*n) sc=o(m*n);
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;

              if(j>0)  up = dp[i][j-1];
              if(i>0) left = dp[i-1][j];

                dp[i][j] = up + left;
            }
        }
    }


	return dp[m-1][n-1];
}