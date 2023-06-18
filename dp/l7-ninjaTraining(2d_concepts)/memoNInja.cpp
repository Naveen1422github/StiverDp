int f(int n, vector<vector<int>> &pt, int li, vector<vector<int>> &dp){

   if(n==0){
       int maxi = 0;
       for(int i=0; i<3; i++){
           if(i!=li){
            maxi = max(maxi, pt[n][i]);
           }
       }

       return maxi;
   }

   if(dp[n][li]!=-1)
   return dp[n][li];
       
    int maxi = 0;
       for(int i=0; i<3; i++){
           if(i!=li){
            maxi = max(maxi,pt[n][i] + f(n-1, pt, i,dp));
           }
    }
    
    dp[n][li] = maxi;

    return maxi;

       
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp (n, vector<int>(4,-1));
    return f(n-1,points, 3, dp);
}