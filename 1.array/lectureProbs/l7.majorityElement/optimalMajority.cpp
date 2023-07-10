// moore's voting algo
#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
    int ct = 0;
    int element ; 

    for(int i=0; i<v.size(); i++){

        if(ct == 0){
            element = v[i];
            ct = 1;
        }
        else if(a[i] == element){
            ct++;
        }
        else ct--;
    }

    return element;
}