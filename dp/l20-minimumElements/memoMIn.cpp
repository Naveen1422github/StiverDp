
//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries


#include <bits/stdc++.h> 
int f(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
   
    if(n == 0){
        if(k%arr[0] == 0) return k/arr[0];
        else return 1e9;
    }

    if(dp[n][k] != -1) return dp[n][k];
    
    int notTake = f(n-1,k,arr, dp);

    int take = 1e9;
  
    if(arr[n]<=k) 
    {
        take = 1 + f(n, k-arr[n], arr, dp);
    }

    return  dp[n][k] = min(take, notTake);

}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    
    vector<vector<int>> dp(n, vector<int> (x+1, -1));

    int ans = f(n-1, x, num, dp);

    if(ans>=1e9) return -1;

    return ans;
}