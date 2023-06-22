int ninjaTraining(int n, vector<vector<int>> &pt)
{
    vector<int> dp (4,-1);

    dp[0] = max(pt[0][1], pt[0][2]);
    dp[1] = max(pt[0][0], pt[0][2]);
    dp[2] = max(pt[0][0], pt[0][1]);
    dp[3] = max(pt[0][1],max(pt[0][0], pt[0][2]));


    for(int i=1; i<n; i++){
        vector<int> temp (4,0);
        for(int j=0; j<4; j++){
            for(int k=0; k<3; k++){
               if(k!=j){
                    temp[j]=max(temp[j], pt[i][k] + dp[k]);  
               }
            }
        }  
        dp = temp;

    }   
    
    return dp[3];

}