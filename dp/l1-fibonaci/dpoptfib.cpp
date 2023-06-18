#include<iostream> 
using namespace std;

// very optimised  tc = o(n) & sc = o(1)

int main()
{
    int n; 
    cin>>n;

    if(n<=1){
        cout<<n;
        return 0;
    }

    int prev2 = 0;
    int prev = 1;
    

    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    cout<<prev;
}