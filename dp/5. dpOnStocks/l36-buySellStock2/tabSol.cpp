//https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp (n+1, vector<long>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            long profit=0;

            if(buy){
                long take = -values[i] + dp[i+1][0];
                long notTake = dp[i+1][1];
                profit = max(take, notTake);
            }
            else{
                long sell = values[i] + dp[i+1][1];
                long notSell = dp[i+1][0];
                profit = max(sell, notSell);
            }

            dp[i][buy] = profit;

        }

    }

    return dp[0][1];
}