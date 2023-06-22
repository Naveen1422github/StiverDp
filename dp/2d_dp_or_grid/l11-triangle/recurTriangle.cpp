#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>&tri, int n){

    if(i==n) return tri[i][j];
    
    int vertDown= tri[i][j] + f( i+1, j, tri, n);
    int diagDown = tri[i][j] + f(i+1, j+1, tri, n);

    return min(vertDown, diagDown); 
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
   return f(0, 0, triangle, n-1);
}