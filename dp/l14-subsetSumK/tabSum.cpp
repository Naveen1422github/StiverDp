//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i=0; i<n; i++){
        dp[i][0]=1;
    }

    if(arr[0]<=k)
    dp[0][arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){

            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i]<=j)
            take = dp[i-1][j-arr[i]];
            
            dp[i][j] = notTake || take;
        }
    }

    return dp[n-1][k];
}