#include <bits/stdc++.h> 

int f(vector<int>&money, int n){

    if(n==0)
    return money[n];

    if(n<0)
    return 0;

    if(n-2 != 0)
    int pick = money[n] + f(money, n-2);
    else
    int pick = money[n];

    int notPick = f(money, n-1);    
 
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vecor<int> anotherArray;
    anotherArray = valueInHouse;
    anotherArray.erase(anotherArray.begin());
    return f(valueInHouse, n-2,anotherArray, n-1);
}