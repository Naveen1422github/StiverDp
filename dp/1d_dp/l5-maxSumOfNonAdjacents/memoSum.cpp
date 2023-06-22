#include <bits/stdc++.h> 

int f(vector<int> &arr, int n, vector<int> &dp){
    
    if(n==0){
       return arr[n];
    }

    if(dp[n] != -1)
    return dp[n];

    int case1 = arr[n] + f(arr, n-2, dp);
    int case2 = f(arr, n-1, dp);
    
    return dp[n] = max(case1, case2);
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return f(nums, n-1, dp);
}