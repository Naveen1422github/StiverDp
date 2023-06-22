//https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//same as buy sell 3 just here cap 0f 2 is cap of k

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &values, int n, int k)
{
        vector<vector<int>> next(2,vector<int>(k+1, 0)), curr(2,vector<int>(k+1, 0));

  
    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            for(int cap=1; cap<=k; cap++){
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

    return next[1][k];
}
