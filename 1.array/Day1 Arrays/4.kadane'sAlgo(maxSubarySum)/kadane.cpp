#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0; 
    long long maxSum = INT_MIN;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxSum = max(sum, maxSum);
        if(sum < 0) sum = 0;
    }

    long long val = 0;

    maxSum = max(val, maxSum); // empty subarray
    return maxSum;
}