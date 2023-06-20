//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



#include <bits/stdc++.h> 

int mod = 1e9 + 7;

int f(int n, int k, vector<int> &arr,vector<vector<int>> &dp){
   
    
    if(n==0){
       if( k==0 && arr[0]==0) return 2;
       if(k==0 || arr[0] == k) return 1;
       return 0;
    } 

    if(dp[n][k] != -1) return dp[n][k];

    int notTake = f(n-1,k,arr, dp)%mod;

    int take = 0;
    if(arr[n]<=k) 
    take = f(n-1, k-arr[n], arr, dp)%mod;

    return dp[n][k] = (take + notTake)%mod;

}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    sort(num.begin(), num.end());
    return f(n-1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }

    if(sum-d<0|| (sum-d)%2!=0) return false;

    findWays(arr, (sum-d)/2);
}


