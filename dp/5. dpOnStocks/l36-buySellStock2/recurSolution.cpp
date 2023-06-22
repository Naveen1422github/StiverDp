
//https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
long f(long *values, int n, int buy, int size){
    
    if(n==size)return 0;

    if(buy){
        int take = -values[n] + f(values, n+1, 0, size);
        int notTake = f(values, n+1, 1, size);
        return max(take, notTake);
    }
    else{
        int sell = values[n] + f(values, n+1, 1, size);
        int notSell = f(values, n+1, 0, size);
        return max(sell, notSell);
    }


}
long getMaximumProfit(long *values, int n)
{
    return f(values, 0, 1, n);
}