//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> dp(k+1,0);

    dp[0]=1;

    if(arr[0]<=k)
    dp[arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        vector<int> curr(k+1,0);
        curr[0]=1;
        for(int j=1; j<=k; j++){

            bool notTake = dp[j];
            bool take = false;
            if(arr[i]<=j)
            take = dp[j-arr[i]];
            
            curr[j] = notTake || take;
        }
        dp = curr;
    }

    return dp[k];
}