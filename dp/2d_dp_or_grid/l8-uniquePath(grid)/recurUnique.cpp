
//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

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