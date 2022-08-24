/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 21:43
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int temp[N],j=0;
    for(int i=0;i<N;i++){
        if(arr[i]%10 != 0){
            temp[j++] = arr[i];
        }
    }
    for(int i=0;i<N;i++)
        if(arr[i]%10 == 0)
            temp[j++] = arr[i];
    
    for(int i=0;i<N;i++)
        cout<<temp[i]<<" ";
    return 0;
}