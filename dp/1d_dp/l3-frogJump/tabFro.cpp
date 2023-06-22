//problem from code studio
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0


#include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights) {

    vector<int> s(n, 0);

    s[0] = 0;

    for(int i=1; i<n; i++){
     int left = s[i-1] + abs(heights[i]-heights[i-1]);
     int right = INT_MAX;

      if(i>1)
      right = s[i-2] + abs(heights[i]-heights[i-2]);
      
      s[i] = min(left, right);

    }

    return s[n-1];

}
