/*
Code by:Eeshan Chanpura
Coded on: 24-08-2022 16:52
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ,p;
    int mn = INT_MAX;
    cin>>n>>p;
    int m[n][n];
    for (int i=0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>m[i][j];
    for(int i=0;i<n;i++)
        sort(m[i],m[i]+n);
    for(int i=0;i<n;i++){
        if (n%2 != 0)
            mn = min(mn, m[i][((n+1)/2)]);
        else
            mn = min(mn, m[i][((n+1)/2)-1]);
    }
    cout<<mn;
    return 0;
}
