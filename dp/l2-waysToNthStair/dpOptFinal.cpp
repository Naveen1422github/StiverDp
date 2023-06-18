//problem from code studio
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650


#include <bits/stdc++.h>
nb 
using namespace std;

int countDistinctWays(int n) {
    
    const int MOD = 1e9 + 7;  // Modulo value for handling large numbers


    if(n<=1)
    return 1;

    long long prev = 1;
    long long prev2 = 1;

    for (int i = 2; i <= n; i++) {
        long long curr = (prev + prev2) % MOD;
        prev2 = prev;
        prev = curr;
    }


    return prev;
}