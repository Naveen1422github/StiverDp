#include <bits/stdc++.h> 
void maxSubarraySum(int arr[], int n)
{
    long long sum = 0; 
    long long maxSum = INT_MIN;
    int start = 0; int endind, startind;

    for(int i=0; i<n; i++){
        if(sum == 0) start = i;
        sum+=arr[i];
        if(sum>maxSum){
            maxSum = max(sum, maxSum);
            startind = start; endind = i;

        }
        if(sum < 0) sum = 0;
    }

    long long val = 0;

    if(maxSum<0) cout<<" "<<endl;
    return ;

    for(int i = startind; i<=endind; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return;
}