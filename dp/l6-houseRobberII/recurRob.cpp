#include <bits/stdc++.h> 

//all solutions of this prob are copy of 5 so i'm not solving them

long long int f(vector<int>&money, int n){

    if(n==0)
    return money[n];

    if(n<0)
    return 0;

    long long int pick = money[n] + f(money, n-2);

    long long int notPick = f(money, n-1);   

    return max(pick, notPick); 
 
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<int> temp1, temp2;

    for(int i=0; i<n; i++)
    {
        if(i!=0)
        temp1.push_back(valueInHouse[i]);
        if(i!=n-1)
        temp2.push_back(valueInHouse[i]);

    }

    if(n==1)
    return valueInHouse[0];

    return max(f(temp1, n-2), f(temp2, n-2));
}