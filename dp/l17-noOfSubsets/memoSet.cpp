//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 

int f(int n, int k, vector<int> &arr,vector<vector<int>> &dp){
   
    
    if(n==0){
       if( k==0 && arr[0]==0) return 2;
       if(k==0 || arr[0] == k) return 1;
       return 0;
    } 

    if(dp[n][k] != -1) return dp[n][k];

    int notTake = f(n-1,k,arr, dp);

    int take = 0;
    if(arr[n]<=k) 
    take = f(n-1, k-arr[n], arr, dp);

    return dp[n][k] = take + notTake;

}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));

    return f(n-1, tar, num, dp);
}