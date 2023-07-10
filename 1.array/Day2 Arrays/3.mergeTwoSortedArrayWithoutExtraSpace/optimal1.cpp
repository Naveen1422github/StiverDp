#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){

    int i = a.size()-1;
    int j = 0;

    while(a[i] > b[j]) {
		swap(a[i], b[j]);
        i--; j++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
