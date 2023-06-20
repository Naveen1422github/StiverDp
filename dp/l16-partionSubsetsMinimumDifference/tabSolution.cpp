//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0; 

    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int k = sum;
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i=0; i<n; i++){
        dp[i][0]=1;
    }

    if(arr[0]<=k)
    dp[0][arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){

            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i]<=j)
            take = dp[i-1][j-arr[i]];
            
            dp[i][j] = notTake || take;
        }
    }

    int mini = -1e7;
    for(int i=0; i<=k; i++){
        if(dp[n-1][i]){
           int set1 = i;
           int set2 = k-i; 
           mini = min(mini, abs(set1-set2));
        }
    }
}
