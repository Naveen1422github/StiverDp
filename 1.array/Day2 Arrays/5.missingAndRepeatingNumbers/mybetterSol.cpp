#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    unordered_map<int, int> m;

    pair<int,int> ans;

    for (int i = 0; i < n; i++) {

        m[arr[i]]++;

        if (m[arr[i]] > 1) {
            ans.second = arr[i];
        }  

    }

    for ( int i = 1; i <= n; i++) {
        
        if (m[i]<1) {
            ans.first = i;
        }
    }

    return ans;
}
