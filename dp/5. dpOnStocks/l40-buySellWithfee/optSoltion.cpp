//https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 
int maximumProfit(int n, int fee, vector<int> &values) {

    vector<int> curr(2,0), next(2,0);

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<2; buy++){
            int profit=0;

            if(buy){
                int take = -values[i] + next[0]-fee;
                int notTake = next[1];
                profit = max(take, notTake);
            }
            else{
                int sell = values[i] + next[1];
                int notSell = next[0];
                profit = max(sell, notSell);
            }

            curr[buy] = profit;

            next = curr;
        }

    }

    return curr[1];
}
