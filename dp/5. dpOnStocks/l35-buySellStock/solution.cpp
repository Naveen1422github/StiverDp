
//https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.

    int mini = prices[0];
    int profit = 0;

    int n = prices.size();

    for(int i=1;i<n;i++){

        int cost = prices[i]-mini;

        profit = max(profit,cost);

        mini = min(mini, prices[i]);
    }

    return profit;
}