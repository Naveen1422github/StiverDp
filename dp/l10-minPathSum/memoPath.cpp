#include <bits/stdc++.h> 

int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>>&dp){

    int mod = 1e9 + 7;

	if(m==0&&n==0) return grid[0][0];
	if(m<0 || n<0) return mod;

    if(dp[m][n]!=-1) return dp[m][n];

	int up = grid[m][n]+f(m,n-1, grid, dp);
	int left = grid[m][n]+f(m-1, n, grid, dp);

	return dp[m][n] = min(up, left);
}


int minSumPath(vector<vector<int>> &grid) {

   int m = grid.size();
   int n = grid[0].size();

   vector<vector<int>>dp(m,vector<int>(n,-1));

   return f(m-1, n-1, grid, dp);
}