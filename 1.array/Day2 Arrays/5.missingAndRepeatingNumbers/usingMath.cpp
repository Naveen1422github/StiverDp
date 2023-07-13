#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;

    int s = 0, s1 = 0;

    for (int i = 0; i < n; i++) {
        s += arr[i];
        s1 += i+1;
    }

    int s2 = 0, s3 = 0;

    for (int i = 0; i < n; i++) {
        s2 = arr[i]*arr[i];
        s3 = (i+1)*(i+1);
    }

    // x - y = s - s1 = a (let)    where x is duplicat and y missing how do i know
    // x^2 - y^2 = s2 - s3    just do s - s1 and see
    // => (x-y)(x+y) = s2 - s3 =>  x+y = (s2 - s3) / x-y = b (let)
    // so (a + b) / 2 = x and (a - b) / 2 = y

    int a = s - s1;
    int b = (s2 - s3) / a;

    ans.first = (a + b) / 2;
    ans.second = (a - b) / 2;

    return ans;
}