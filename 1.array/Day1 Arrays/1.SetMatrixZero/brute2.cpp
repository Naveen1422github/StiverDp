
//https://www.codingninjas.com/studio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge

// tc= o(n*m*(n+m) + (n*m)) sc= o(1) 

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	
    int n = mat.size();
    int m = mat[0].size();

	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(mat[i][j]==0){
                for(int p=0;p<n;p++){
                    if(mat[p][j]!=0)
                    mat[p][j]=-1;
                }
                for(int q=0;q<m;q++){
                    if(mat[i][q]!=0)
                    mat[i][q]=-1;
                }
            }

        }
    }

	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==-1)
            mat[i][j]=0;
        }
    }
}
