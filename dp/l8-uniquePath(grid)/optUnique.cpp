//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


int uniquePaths(int m, int n) {
    vector<int> prev (n,-1), curr(n,-1);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;

              if(j>0)  up = curr[j-1];
              if(i>0) left = prev[j];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

	return prev[n-1];
}