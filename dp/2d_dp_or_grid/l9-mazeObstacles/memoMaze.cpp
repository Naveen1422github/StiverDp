
int f(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){

    int mod = 1e9+7; 

    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;

    if(mat[n][m]==-1) return 0;

    if(dp[n][m]!=-1) return dp[n][m];

    int up = f(n,m-1,mat, dp)%mod;
    int left = f(n-1, m, mat, dp)%mod;

    return dp[n][m] = (up + left)%mod ;
}

int mazeObstacles(int n, int m, vector< vector<int>> &mat) {
    
    vector<vector<int>> dp (n,vector<int>(m,-1));
    
    if(mat[0][0]==-1 || mat[n-1][m-1]==-1) return 0;
    return f(n-1, m-1, mat, dp);
}