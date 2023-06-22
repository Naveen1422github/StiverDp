#include <bits/stdc++.h> 

// tc = 2^(m*n)  sc = o((m-1)+(n-1))

int f(int m, int n){

	if(m==0&&n==0) return 1;

	if(m<0 || n<0) return 0;


	int up = f(m,n-1);
	int left = f(m-1, n);

	return up + left;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	return f(m-1, n-1);
}