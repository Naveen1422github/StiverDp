//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// tc=2^n sc = n
bool f(int n, int k, vector<int> &arr){

    if(k==0) return true;
    if(n==0) return k==arr[0];

    int notTake = f(n-1,k,arr);

    int take = false;
    if(arr[n]<=k) 
    take = f(n-1, k-arr[n], arr);

    return take || notTake;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1, k, arr);
}