#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0; 
    long long maxSum = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<j; k++){
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
            sum = 0;
        }
    }

    return maxSum;
}