#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;

  ans.push_back(vector<long long int>({1}));
  if(n==1) return ans;

  for(int i=0; i<n-1; i++){
    
    vector<long long int> vec = ans[i]; 
    vector<long long int> vec2;
    for(int j=0; j<=i+1; j++){
        long long int left;
        long long int right;

        if(j-1<0) left = 0;
        else left = vec[j-1];

        if(j>i) right = 0; 
        else right = vec[j];

       vec2.push_back(left+right); 
    }

    ans.push_back(vec2);
  }

  return ans;
  
}
