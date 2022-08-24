/*
Code by:Eeshan Chanpura
Cooded on: 15-06-2022 19:43

Actual number : 0 1 2 3 4 5 6 7 8 9 
Replace number: 9 8 7 6 5 4 3 2 1 0

Input: 105201
Outpu: 894798
Exp  : (9-1)(9-0)(9-5).....
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[10]={0};
    for(int i=0;i<10;i++)
        arr[i]=9-i;
    if(n<0 || n>1000000){
        cout<<"Not Possible";
        return 0;
    }
    if(n==0){
        cout<<9;
        return 0;
    }
    int ans=0, power=1;
    while(n>0){
        int rem=n%10;
        int replace=arr[rem];
        ans += replace*power;
        power *=10;
        n/=10;
    }
    cout<<ans;
    return 0;
}