#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//tc = 

int f(string &s, string &t, int n, int m, vector<vector<int>> &dp) {

    if(n<0 || m<0) return 0;
    
    if(dp[n][m] != -1) return dp[n][m];

    if (s[n] == t[m]) {
      int take = 1 + f(s, t, n - 1, m - 1, dp);
      return take;
    }

    int notTake = max(f(s,t,n-1,m,dp), f(s,t,n,m-1, dp));

    return dp[n][m] = notTake;
}



int lcs(string s, string t)
{
	int n = s.length();
	int m = t.length();
    
  vector<vector<int>> dp (n, vector<int>(m, -1));

	return f(s, t, n-1, m-1, dp);
} 