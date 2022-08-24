/*
Code by:Eeshan Chanpura
Coded on: 24-08-2022 11:40
*/
#include<bits/stdc++.h>
using namespace std;

int find_count(vector<int>& S, int n, int x){
    int N=n+x-2;
    int r=n-1;
    double res=1;
    for(int i=1;i<=r;++i)   
        res=res*(N-r+i)/i;
    if(x&1)
        return (int)res;
    else
        return (int)res+1;
}
int main(){
    int n; cin>>n;
    int x; cin>>x;
    vector<int> S(n);
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    cout<<find_count(S,n,x);

    return 0;
}