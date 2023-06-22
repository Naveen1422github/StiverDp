//problem from code studio
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0


#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights) {

    int prev = 0 ; 
    
    int prev2 = INT_MAX;

    for(int i=1; i<n; i++){
     int left = prev + abs(heights[i]-heights[i-1]);
     int right = INT_MAX;

      if(i>1)
      right = prev2 + abs(heights[i]-heights[i-2]);
      
      int curr = min(left, right);

      prev2 = prev;
      prev = curr;

    }

    return prev;

}
