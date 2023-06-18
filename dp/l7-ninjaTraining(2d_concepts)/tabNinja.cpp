
int ninjaTraining(int n, vector<vector<int>> &pt)
{
    vector<vector<int>> dp (n, vector<int>(4,-1));

    dp[0][0] = max(pt[0][1], pt[0][2]);
    dp[0][1] = max(pt[0][0], pt[0][2]);
    dp[0][2] = max(pt[0][0], pt[0][1]);
    dp[0][3] = max(pt[0][1],max(pt[0][0], pt[0][2]));


    for(int i=1; i<n; i++){
        for(int j=0; j<4; j++){
            int maxi = 0;
            for(int k=0; k<3; k++){
               if(k!=j){
                    dp[i][j] = pt[i][k] + dp[i-1][k];
                    maxi = max(maxi, dp[i][j]);
               }
            }
            dp[i][j] = maxi;
        }
    }   
    
    return dp[n-1][3];

}