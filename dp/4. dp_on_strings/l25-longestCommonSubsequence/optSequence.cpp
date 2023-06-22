
//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include<bits/stdc++.h>

int lcs(string s, string t)
{
	int n = s.length();
	int m = t.length();
    
    vector<int> prev (m+1, -1), curr(m+1, -1);

    for(int j=0; j<=m; j++) prev[j] = 0;

    curr = prev;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (s[i-1] == t[j-1]) 
            curr[j] = 1 + prev[j-1]; 
            else
            curr[j] = max(prev[j], curr[j-1]);

        }
        prev = curr;
    }

	return  prev[m];
}