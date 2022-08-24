/*
Code by:Eeshan Chanpura
Coded on: 18-08-2022 18:48
*/
#include<bits/stdc++.h>
using namespace std;

int total_rupees(int r1,int n, int r2, int x){
    int tot_time = ceil(x*1.0/60); 
    int ans = 0;
    if(n > tot_time) return  r1*tot_time;
    do{
        ans += r1*n;
        tot_time -= n;
    }while(tot_time >= n);
    ans += r2*tot_time;
    return ans;
}
int main(){
    int r1=30,n=4,r2=35,x=600;
    cout<<total_rupees(r1,n,r2,x);
    return 0;
}