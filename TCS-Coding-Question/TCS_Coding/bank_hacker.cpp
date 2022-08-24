/*
Code by:Eeshan Chanpura
Coded on: 19-08-2022 18:51
*/
#include<bits/stdc++.h>
using namespace std;

bool hack(int n, int curr){
    if( curr == n) return true;
    if(curr > n) return false;
    return hack(n,curr*10) || hack(n,curr*20);
    //return (n%10 == 0 || n%20 == 0);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1)
            cout<<"Yes";
        else{
            if(hack(n,1))
                cout<<"Yes";
            else    
                cout<<"No";
        }
    }
    return 0;
}