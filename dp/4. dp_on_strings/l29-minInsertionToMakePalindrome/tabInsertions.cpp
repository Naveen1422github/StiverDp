
https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//to find no of insetions, longetst plindrom subsequence in string 
//now u you need to insert only those element to string which are
// not part of palindrom subsequence that means 
// to no of insertions = string lenth - palindromic subsequence length

#include <bits/stdc++.h> 

int minInsertion(string &s)
{
        int n = s.length();
	int m = n;
    string t = s;
    
    reverse(s.begin(), s.end());


    
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

	return n - dp[n][m];
}