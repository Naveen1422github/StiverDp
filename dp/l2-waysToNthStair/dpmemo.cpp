#include <bits/stdc++.h> 
//problem from code studio
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650

// solution doesn't work for n>43 to make it work i just have to use mod 

//other optimized solution for n<43 are same as fibonaci (if didn't use mod)


int f(int n, vector<int> &dp){
    if(n<=1)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp (n+1, -1);

    return f(n, dp);
}