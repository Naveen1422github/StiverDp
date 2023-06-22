
//https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <bits/stdc++.h> 

int f( int n, int mw, vector<int> &v, vector<int> &w){
    

	if(n==0){
		if(w[0]<=mw) 
           return (mw/w[0])*v[0];
		else 
          return 0;
	}

    int notPick = f(n-1, mw,v,w);

    int pick = INT_MIN;
	if(w[n]<=mw)
	   pick = v[n] + f(n,mw-w[n],v, w);

	return max(pick, notPick);

}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return f(n-1, w,profit, weight);
}
