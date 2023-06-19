//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
bool f(int n, int k, vector<int> &arr, vector<vector<int>> &dp){

    if(k==0) return true;
    if(n==0) return k==arr[0];

    if(dp[n][k]!=-1) return dp[n][k];

    bool notTake = f(n-1,k,arr,dp);

    bool take = false;
    if(arr[n]<=k) 
    take = f(n-1, k-arr[n], arr,dp);

    return dp[n][k] = take | notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1, k, arr,dp);
}