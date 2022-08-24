/*
Code by:Eeshan Chanpura
Coded on: 21-08-2022 19:20
*/
#include<bits/stdc++.h>
using namespace std;

int game_posibility(int n){
    if(n&1)
        return n;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        if(i<=2)
            arr[i]=i;
        else
            arr[i]=arr[i-1]+(i-1)*arr[i-2];
    }
    return arr[n];
}

int main(){
    int n;
    cin>>n;
    cout<<game_posibility(n);
    return 0;
}