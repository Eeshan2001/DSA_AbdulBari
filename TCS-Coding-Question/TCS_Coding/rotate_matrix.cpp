/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 21:33
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    
    for(int i=0;i<n;i++)
        for(int j=0; j<i; j++)
            swap(arr[i][j],arr[j][i]);
    
    for(int i=0;i<n;i++)
        reverse(arr[i],arr[i]+n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}