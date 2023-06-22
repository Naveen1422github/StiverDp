
//https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include<bits/stdc++.h>

long f(long *values, int n, int buy, int size,vector<vector<long>> &dp ){
    
    if(n==size)return 0;

    if(dp[n][buy]!=-1) return dp[n][buy];

    long profit=0;

    if(buy){
        long take = -values[n] + f(values, n+1, 0, size,dp);
        long notTake = f(values, n+1, 1, size,dp);
        profit = max(take, notTake);
    }
    else{
        long sell = values[n] + f(values, n+1, 1, size,dp);
        long notSell = f(values, n+1, 0, size,dp);
        profit = max(sell, notSell);
    }

    return dp[n][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp (n, vector<long>(2, -1));
    return f(values, 0, 1, n, dp);
}