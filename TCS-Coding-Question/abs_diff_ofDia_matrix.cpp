/*
Code by:Eeshan Chanpura
Cooded on: 15-06-2022 19:06
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i=0,j=0,n,ld=0,rd=0;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    // left diagonal sum
    i=0;j=0;
    while(i!=n && j!=n){
        ld+=arr[i++][j++];
    }

    // right diagonal sum
    i=0;j=n-1;
    while(i!=n && j>=0){
        rd+=arr[i++][j--];
    }


    cout<<abs(ld-rd);
    return 0;
}