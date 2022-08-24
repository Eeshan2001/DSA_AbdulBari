/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 14:25
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
   // int arr[]={100,60,70,65,80,85};
    int arr[N];
    for(int i=0;i<N;i++)   cin>>arr[i];
    for(int i=0;i<N;i++){
        int count=1;
        for(int j=i-1; j>=0 ;j--){
            if(arr[j] <= arr[i])
                count++;
            else
                break;
        }
        cout<<count<<" ";
    }
    return 0;
}