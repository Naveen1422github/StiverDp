//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 
int f(int n, int k, vector<int> &arr){
   
    if(n==0){
       if( k==0 && arr[0]==0) return 2;
       if(k==0 || arr[0] == k) return 1;
       return 0;
    } 

    int notTake = f(n-1,k,arr);

    int take = 0;
    if(arr[n]<=k) 
    take = f(n-1, k-arr[n], arr);

    return  take + notTake;

}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
  
    return f(n-1, tar, num);
}