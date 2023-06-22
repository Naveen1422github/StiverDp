
//https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 

long f(int n, int k, int *arr , vector<vector<long>> &dp){
   

    if(n == 0){
        if(k%arr[0] == 0) return 1;
        else return 0;
    }

    if(dp[n][k]!=-1) return dp[n][k];

    long notTake = f(n-1,k,arr, dp);

    long take = 0;
  
    if(arr[n]<=k) 
    {
        take = f(n, k-arr[n], arr, dp);
    }

    return  dp[n][k] =  take + notTake;

}



long countWaysToMakeChange(int *num, int n, int x)
{
    vector<vector<long>> dp(n, vector<long>(x+1, -1));
    long ans = f(n-1, x, num, dp);

    return ans;
}