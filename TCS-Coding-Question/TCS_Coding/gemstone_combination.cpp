/*
Code by:Eeshan Chanpura
Coded on: 21-08-2022 18:25
*/

//          RECURSION

#include<bits/stdc++.h>
using namespace std;

int demo(int r, int g, int t , int ref){
    if(r<0 || t<0 || g<0) return 0;
    if(r==1 && g==0 && t==0 && ref == 0) return 1;
    if(r==0 && g==1 && t==0 && ref == 1) return 1;
    if(r==0 && g==0 && t==1 && ref == 2) return 1;
    if(ref == 0)
        return demo(r-1,g,t,1) + demo(r-1,g,t,2);
    if(ref == 1)
        return demo(r,g-1,t,0) + demo(r,g-1,t,2);
    if(ref == 2)
        return demo(r,g,t-1,0) + demo(r,g,t-1,1);
}

int possibilities(int r,int g, int t){
    return demo(r,g,t,0)+demo(r,g,t,1)+demo(r,g,t,2);
}

int main(){
    int r,g,t;
    cin>>r>>g>>t;
    cout<<possibilities(r,g,t);
    return 0;
}