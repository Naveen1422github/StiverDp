// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//recursive sol

int f(int n, vector<vector<int>> &pt, int li){

   if(n==0){
       int maxi = 0;
       for(int i=0; i<3; i++){
           if(i!=li){
            maxi = max(maxi, pt[n][i]);
           }
       }

       return maxi;
   }
       
    int maxi = 0;
       for(int i=0; i<3; i++){
           if(i!=li){
            maxi = max(maxi,pt[n][i] + f(n-1, pt, i));
           }
    }

    return maxi;

       
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    f(n-1,points, 3);
}