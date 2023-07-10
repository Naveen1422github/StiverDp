//https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<bits/stdc++.h>

vector<int> nextGreaterPermutation(vector<int> &a) {  

    int n = a.size();
    int ind = -1; 

    //problem is divided in 3 seg 
    // 1. find break point

    for (int i = n-2; i >= 0; i--) {

        if (a[i]<a[i+1]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        sort(a.begin(), a.end());
        return a;
    }

    // 2. swap the element at index with next greater element

    for (int i = n-1; i > ind; i--) {
        if (a[i]>a[ind]) {
            swap(a[i], a[ind]);
            break;
        }
    }

    // 3. arrange array in increasing order after ind
    // since arranged in decreasing order we just have to reverse

    reverse(a.begin() + ind+1, a.end());

    return a;
