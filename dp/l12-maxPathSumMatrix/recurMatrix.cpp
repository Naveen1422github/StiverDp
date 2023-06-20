//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



#include <bits/stdc++.h> 

int f(int i, int j, int n, int m, vector<vector<int>> &mat){
    
    if(j<0 || j>m) return 0;

    if(i==n) return mat[i][j];

    int botLeft = mat[i][j] + f(i+1, j-1, n, m, mat);
    int botRight = mat[i][j] + f(i+1, j+1, n, m,mat);
    int botStright = mat[i][j] + f(i+1, j, n, m,mat);

    return max(botStright, max(botLeft, botRight));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int maxi = -1e9+7;

    for(int p=0; p<m; p++){
      maxi = max(maxi,f(0,p,n-1,m-1,matrix));
    }

    return maxi;
}
