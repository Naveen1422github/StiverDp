// tc = 2n,  sc = 1
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==0) zero++;
        if(arr[i]==1) one++;
        if(arr[i]==2) two++;
    }


    int i=0; 
    while(zero--){
        arr[i] = 0;
        i++;
    }

    while(one--){
        arr[i] = 1;
        i++;
    }

    while(two--){
        arr[i] = 2;
        i++;
    }

}