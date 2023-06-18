//problem from code studio
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0


//memo version  tc=o(n), sc=o(n) for stack space + o(n) for dp array


#include <bits/stdc++.h> 
using namespace std;

int f(int n, vector<int> &heights, vector<int> &s){

      if(n<=0)
      return 0;

      if(s[n]!=-1)
      {
        return s[n];
      }

      int left = f(n-1, heights, s) + abs(heights[n]-heights[n-1]);

     int right=INT_MAX;
      if(n>1)
      right = f(n-2, heights, s) + abs(heights[n]-heights[n-2]);

       s[n] = min(left, right);

   return s[n];

}

int frogJump(int n, vector<int> &heights) {

    vector<int> s(n, -1);

    return f(n-1, heights, s);

}
