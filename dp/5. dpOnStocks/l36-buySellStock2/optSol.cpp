#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{

   vector<long> curr(2,0), next(2,0);

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            long profit=0;

            if(buy){
                long take = -values[i] + next[0];
                long notTake = next[1];
                profit = max(take, notTake);
            }
            else{
                long sell = values[i] + next[1];
                long notSell = next[0];
                profit = max(sell, notSell);
            }

            curr[buy] = profit;

            next = curr;
        }

    }

    return curr[1];
}