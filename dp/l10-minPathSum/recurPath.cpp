#include <bits/stdc++.h> 

int f(int m, int n, vector<vector<int>> &grid){

    int mod = 1e9 + 7;

	if(m==0&&n==0) return grid[0][0];

	if(m<0 || n<0) return ;


	int up = grid[m][n]+f(m,n-1, grid);
	int left = grid[m][n]+f(m-1, n, grid);

	return min(up, left);
}


int minSumPath(vector<vector<int>> &grid) {
   
   int m = grid.size();
   int n = grid[0].size();

   return f(m-1, n-1, grid);
}