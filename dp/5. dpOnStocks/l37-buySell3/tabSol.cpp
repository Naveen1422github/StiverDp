//https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>

int maxProfit(vector<int> &values, int n)
{
    vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2,vector<int>(3, 0)));

  
    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            for(int cap=1; cap<=2; cap++){
            int profit=0;

            if(buy){
                int take = -values[i] + dp[i+1][0][cap];
                int notTake = dp[i+1][1][cap];
                profit = max(take, notTake);
            }
            else{
                int sell = values[i] + dp[i+1][1][cap-1];
                int notSell = dp[i+1][0][cap];
                profit = max(sell, notSell);
            }

            dp[i][buy][cap] = profit;
        }

        }

    }

    return dp[0][1][2];
}