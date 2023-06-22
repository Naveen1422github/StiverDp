//https://www.codingninjas.com/studio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 
int stockProfit(vector<int> &values){
   
   int n=values.size();
   vector<long> curr(2,0), next(2,0), next2(2,0);

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            long profit=0;

            if(buy){
                long take = -values[i] + next[0];
                long notTake = next[1];
                profit = max(take, notTake);
            }
            else{
                long sell = values[i] + next2[1];
                long notSell = next[0];
                profit = max(sell, notSell);
            }

            curr[buy] = profit;
            
            
        }
        next2 = next;
        next = curr;

    }

    return curr[1];
}