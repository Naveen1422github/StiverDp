
   int mod = 1e9 + 7;

   int m = grid.size();
   int n = grid[0].size();

   vector<int>prev(n,0);

   for(int i=0; i<m; i++){
    vector<int>curr(n,0);
    for(int j=0; j<n; j++){
        if(i==0 && j==0) curr[0] = grid[0][0];
        else{
            int down = mod;
            int right = mod;

            if(j>0)
            down = grid[i][j] + curr[j-1];
            if(i>0)
            right = grid[i][j] + prev[j];
            
            curr[j] = min(down, right);
        }
    }

    prev = curr;
   }

   return prev[n-1];
}