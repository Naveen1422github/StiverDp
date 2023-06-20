#include <bits/stdc++.h> 

int f(vector<int> &w, vector<int> &v, int n, int mw){


	if(n==0){
		if(w[0]<=mw) 
           return v[0];
		else 
          return 0;
	}

    int notPick = f(w,v,n-1, mw);

    int pick = INT_MIN;
	if(w[n]<=mw)
	   pick = v[n] + f(w,v,n-1,mw-w[n]);

	return max(pick, notPick);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	return f(weight, value, n-1, maxWeight);
}
