
//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


int f(string &s, string &t, int n, int m) {

    if(n<0 || m<0) return 0;

    if (s[n] == t[m]) {
      int take = 1 + f(s, t, n - 1, m - 1);
      return take;
    }

    int notTake = max(f(s,t,n-1,m), f(s,t,n,m-1));

    return notTake;
}



int lcs(string s, string t)
{
	int n = s.length();
	int m = t.length();

	return f(s, t, n-1, m-1);
}