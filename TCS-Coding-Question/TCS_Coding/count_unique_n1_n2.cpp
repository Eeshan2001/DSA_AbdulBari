/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 18:09
*/
#include<bits/stdc++.h>
using namespace std;

int isUnique(int n){
    set<int> s;
    while(n){
        int a = n%10;
        if(s.find(a) != s.end())
            return 0;
        s.insert(a);
        n /= 10;
    }
    return 1;
}

int main(){
    int cnt=0, n1,n2;
    cin>>n1>>n2;
    for(int i=n1;i<=n2;i++)
        if(isUnique(i))
            cnt++;
    cout<<cnt;
    return 0;
}