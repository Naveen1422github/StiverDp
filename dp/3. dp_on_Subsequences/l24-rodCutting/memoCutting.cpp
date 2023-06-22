
//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



#include <bits/stdc++.h> 

//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


int f(vector<int> &v, int ind, int n, vector<vector<int>> &dp){


	if(ind==0){
           return n*v[0];	
	}

    if(dp[ind][n]!=-1) return dp[ind][n];
    int notPick = f(v,ind-1, n, dp);

    int pick = INT_MIN;
	int rodLength = ind+1;
	if(rodLength<=n)
	pick = v[ind] + f(v,ind, n-rodLength,dp);

	return dp[ind][n] = max(pick, notPick);

}




int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp (n, vector<int> (n+1, -1));
    return f(price, n-1, n,dp);
}
