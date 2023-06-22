//https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>

int maxProfit(vector<int> &values, int n)
{
    vector<vector<int>> next(2,vector<int>(3, 0)), curr(2,vector<int>(3, 0));

  
    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            for(int cap=1; cap<=2; cap++){
            int profit=0;

            if(buy){
                int take = -values[i] + next[0][cap];
                int notTake = next[1][cap];
                profit = max(take, notTake);
            }
            else{
                int sell = values[i] + next[1][cap-1];
                int notSell = next[0][cap];
                profit = max(sell, notSell);
            }

            curr[buy][cap] = profit;

          }

        }

        next = curr;

    }

    return next[1][2];
}