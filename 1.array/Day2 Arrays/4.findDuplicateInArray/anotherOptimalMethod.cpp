#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	int ind = 0;
	for(int i=0; i<n; i++) {
        
        ind = abs(arr[i])-1;

        arr[ind] *= -1;

        if(arr[ind] > 0) return abs(arr[i]);

	}
}
