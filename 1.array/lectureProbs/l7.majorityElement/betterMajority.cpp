#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
    unordered_map<int, int> m;

    int n = v.size();
    int f = n/2;

    for(int i=0; i<n; i++){
        m[v[i]]++;
    }

    for(auto it:m){
        if(it.second>f) return it.first;
    }
}