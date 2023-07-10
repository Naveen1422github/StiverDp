
// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h> 

int f(vector<int> &arr, int n){
    
    if(n==0){
       return arr[n];
    }

    int case1 = arr[n] + f(arr, n-2);
    int case2 = f(arr, n-1);
    
    return max(case1, case2);
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    return f(nums, n-1);
}