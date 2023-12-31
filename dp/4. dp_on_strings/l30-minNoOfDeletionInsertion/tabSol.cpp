
//https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// first find lc subsquece in s1, s2 not to convert s1 -> s2
// if n=lens1, m=lens2 l=lenLCS then
// we need n-l deletion and m-l insertion 
// that means total operations = n+m - 2*l 

#include <bits/stdc++.h>

int canYouMake(string &s, string &t)
{
    int n = s.length();
	int m = t.length();
    
    vector<vector<int>> dp (n+1, vector<int>(m+1, -1));

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (s[i-1] == t[j-1]) 
            dp[i][j] = 1 + dp[i-1][j-1]; 
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        }
    }

	return n+m - 2 * dp[n][m];
}