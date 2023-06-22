#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>&tri, int n, vector<vector<int>>& dp){

    if(i==n) return tri[i][j];

    if(dp[i][j]!= -1) return dp[i][j];
    
    int vertDown= tri[i][j] + f( i+1, j, tri, n, dp);
    int diagDown = tri[i][j] + f(i+1, j+1, tri, n, dp);

    return dp[i][j]=min(vertDown, diagDown); 
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
   vector<vector<int>>dp (n, vector<int>(n,-1));
   return f(0, 0, triangle, n-1, dp);
}