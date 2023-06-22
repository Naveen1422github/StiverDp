#include<iostream> 
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

//homework question if frog can jump for 1 to k steps at a time (i did it my self)

int f(int n, vector<int> h, int k){
    if(n==0) return 0;

    int ans = INT_MAX;

    for(int i=1; i<=k; i++){
        
        int left = INT_MAX;
        int right = INT_MAX;

        if(n>=i) 
        left = f(n-i,h,k) + abs(h[n]-h[n-i]);
        ans = min(ans,left);
    }

    return ans;
}

int main(){
    int n = 8;
    int k = 4;
    vector<int> h {10, 20, 30, 10, 50, 10, 60, 20};

    cout<< f(n-1, h, k);
}