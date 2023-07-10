
// dutch nation flag algo
// tc = o(N)
#include<bits/stdc++.h>

void sortArray(vector<int>& arr, int n)
{
    int low = 0; 
    int mid = 0; 
    int high = n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}