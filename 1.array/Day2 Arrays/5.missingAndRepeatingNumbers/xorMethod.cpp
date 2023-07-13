#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;

    int xor = 0;

    for (int i = 0; i < n; i++) {
        xor ^= arr[i] ^ (i+1);
    }

    //will see later
    return ans;
}