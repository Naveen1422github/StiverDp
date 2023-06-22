#include <bits/stdc++.h> 

int f(int i, int j1, int j2,vector<vector<int>> &grid, int n, int m){

    if(j1<0 || j2<0 || j1>m || j2>m) return -1e7;

    if(i==n){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    } 

    int aliceBob = -1e7;
    for(int dj1=-1; dj1<=+1; dj1++){
        for(int dj2=-1; dj2<=+1; dj2++){

            int value = 0;
            if(j1==j2 )
            value = grid[i][j1];
            else
            value = grid[i][j1] + grid[i][j2];

            aliceBob = max(aliceBob, value + f(i+1, j1+dj1, j2+dj2, grid, n, m));
            
        }
    }

    return aliceBob;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return f(0,0,c-1,grid, r-1, c-1);
}