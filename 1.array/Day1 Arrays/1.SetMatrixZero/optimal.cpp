
//https://www.codingninjas.com/studio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge

// tc= o(2*n*m) sc= o(1)

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	
    int n = mat.size();
    int m = mat[0].size();

    int col0 = 1;
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
                mat[i][0] = 0;
                if(j==0)
                col0=0;
                else
                mat[0][j] = 0;
            }
            

        }
    }

	for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){

            if(mat[i][j] != 0)
            if(mat[i][0]==0 || mat[0][j]==0){
                mat[i][j] = 0;
            }
        }
    }
    
    if(mat[0][0]==0)
    {   for(int j=0;j<m;j++){
            mat[0][j] = 0;
        }
    }

    if(col0==0){
        for(int i=0;i<n;i++){
            mat[i][0] = 0;
        }
    }

}
