
//https://www.codingninjas.com/studio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge

// tc= o(2*n*m) sc= o(n+m)

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	
    int n = mat.size();
    int m = mat[0].size();

    vector<int> row(n, 0), col(m, 0);

	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i]==1 || col[j]==1){
                mat[i][j] = 0;
            }
        }
    }
}
