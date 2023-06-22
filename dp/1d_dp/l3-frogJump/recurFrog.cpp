//problem from code studio
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

// tc = sc = o(n^2)
int frogJump(int n, vector<int> &heights) {

      if(n<=1)
      return 0;

      int left = frogJump(n-1, heights) + abs(heights[n-1]-heights[n-2]);

     int right;
      if(n>2)
      right = frogJump(n-2, heights) + abs(heights[n-1]-heights[n-3]);
      else
      right = INT_MAX;

      int ans = min(left, right);


 
   return ans;
}