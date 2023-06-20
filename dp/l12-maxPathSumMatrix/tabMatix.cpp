//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



#include <bits/stdc++.h> 

int f(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    
    if(j<0 || j>m) return -1e8;

    if(i==n) return mat[i][j];

    if(dp[i][j]!=-1e8) return dp[i][j];

    int botLeft = mat[i][j] + f(i+1, j-1, n, m, mat,dp);
    int botRight = mat[i][j] + f(i+1, j+1, n, m,mat, dp);
    int botStright = mat[i][j] + f(i+1, j, n, m,mat, dp);

    return dp[i][j] = max(botStright, max(botLeft, botRight));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int maxi = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m, -1e8));
    
    for(int j=0; j<m; j++){
        dp[0][j] = mat[0][j];
    }

    for(int j=0; j<m; p++){
        for(int i=0; i<n; i++){

            int botLeft = mat[i][j] + dp[i-1][j]
            int botRight = mat[i][j] + f(i+1, j+1, n, m,mat, dp);
            int botStright = mat[i][j] + f(i+1, j, n, m,mat, dp);

        }
    }

      maxi = max(maxi,f(0,p,n-1,m-1,matrix, dp));
    return maxi;
}
