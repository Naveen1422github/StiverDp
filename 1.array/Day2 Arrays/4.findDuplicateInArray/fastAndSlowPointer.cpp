#include <bits/stdc++.h>

// tc = o(n)

int findDuplicate(vector<int> &arr, int n){

    int fast = arr[0];
    int slow = arr[0];

// traverse till slow != fast
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while (slow != fast);

// take fast at 0

    fast = arr[0];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
