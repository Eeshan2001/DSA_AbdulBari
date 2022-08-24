/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 14:37
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum = 0;
    sum = accumulate(arr,arr+n,sum);
    for(int i=0;i<n;i++){
        sum -= arr[i];
        arr[i] = sum;
    }
    for(int i:arr)
        cout<<i<<" ";
    return 0;
}