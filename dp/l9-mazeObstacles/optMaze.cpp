int mazeObstacles(int n, int m, vector< vector<int>> &mat) {

    int mod = 1e9+7;
    
    vector<int> prev (m,0);
    
    if(mat[0][0]==-1 || mat[n-1][m-1]==-1) return 0;
    

    for(int i=0; i<n; i++){
        vector<int> curr (m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) curr[j] = 1;
            else{
                int down = 0;
                int right = 0;
                if(mat[i][j] != -1){
                    if(j-1>=0)
                    down = curr[j-1];
                    if(i-1>=0)
                    right = prev[j];

                }

           curr[j] = (down + right)%mod;
            }
        }
        prev = curr;

    }

    return prev[m-1];
}int mazeObstacles(int n, int m, vector< vector<int>> &mat) {

    int mod = 1e9+7;
    
    vector<int> prev (m,0);
    
    if(mat[0][0]==-1 || mat[n-1][m-1]==-1) return 0;
    

    for(int i=0; i<n; i++){
        vector<int> curr (m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) curr[j] = 1;
            else{
                int down = 0;
                int right = 0;
                if(mat[i][j] != -1){
                    if(j-1>=0)
                    down = curr[j-1];
                    if(i-1>=0)
                    right = prev[j];

                }

           curr[j] = (down + right)%mod;
            }
        }
        prev = curr;

    }

    return prev[m-1];
}