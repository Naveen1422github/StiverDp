
//https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 
int f(vector<int> &values, int n, int buy, int size, vector<vector<vector<int>>> &dp, int cap ){
    
    if(cap == 0) return 0;
    if(n==size)return 0;

    if(dp[n][buy][cap]!=-1) return dp[n][buy][cap];

    int profit=0;

    if(buy){
        int take = -values[n] + f(values, n+1, 0, size,dp, cap);
        int notTake = f(values, n+1, 1, size,dp, cap);
        profit = max(take, notTake);
    }
    else{
        int sell = values[n] + f(values, n+1, 1, size,dp, cap-1);
        int notSell = f(values, n+1, 0, size,dp, cap);
        profit = max(sell, notSell);
    }

    return dp[n][buy][cap] = profit;
}


int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int>(3, -1)));
    return f(prices, 0, 1, n, dp, 2);
}
