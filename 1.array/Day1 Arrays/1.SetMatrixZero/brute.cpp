
//https://www.codingninjas.com/studio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge

// tc= o( n*m*(n+m) ) sc= o(n*m)

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	
    int n = mat.size();
    int m = mat[0].size();
	vector<vector<int>> pat = mat;

	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(pat[i][j]==0){
                for(int p=0;p<n;p++){
                    mat[p][j]=0;
                }
                for(int q=0;q<m;q++){
                    mat[i][q]=0;
                }
            }

        }
    }
}
