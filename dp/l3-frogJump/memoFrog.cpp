//problem from code studio
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0


//memo version  tc=o(n), sc=o(n) for stack space + o(n) for dp array


#include <bits/stdc++.h> 


int f(int n, vector<int> &heights, vector<int> &dp){

      if(n<=0) return 0;

      if(dp[n]!=-1) return dp[n];
      

      int left = f(n-1, heights,dp) + abs(heights[n]-heights[n-1]);

     int right=INT_MAX;
      if(n>1)
      right = f(n-2, heights, dp) + abs(heights[n]-heights[n-2]);
   
   return  dp[n] = min(right, left);

}

int frogJump(int n, vector<int> &heights) {

    vector<int> dp(n, -1);

    return f(n-1, heights, dp);

}