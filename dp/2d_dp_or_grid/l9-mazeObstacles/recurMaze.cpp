
//https://www.codingninjas.com/studio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

int f(int n, int m, vector<vector<int>> &mat){

    int mod = 1e9+7; 

    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;

    if(mat[n][m]==-1) return 0;

    int up = f(n,m-1,mat)%mod;
    int left = f(n-1, m, mat)%mod;

    return (up + left)%mod ;
}

int mazeObstacles(int n, int m, vector< vector<int>> &mat) {

    if(mat[0][0]==-1 || mat[n-1][m-1]==-1) return 0;
    return f(n-1, m-1, mat);
}