/*
Code by:Eeshan Chanpura
Coded on: 18-08-2022 22:00
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];
    for(int i=0; i <n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    int sr = 0;
    int er = n-1;
    int sc = 0;
    int ec = m-1;
    int cnt = 0;
    while(cnt < n*m){
        for(int j=sc;j<=ec;j++){
            cout<<arr[sr][j]<<" ";
            cnt++;
        }
        sr++;
        if(cnt == n*m) break;

        for(int j=sr;j<=er;j++)
        {
            cout<<arr[j][ec]<<" ";
            cnt++;
        }
        ec--;
        if(cnt == n*m ) break;

        for(int j=ec;j>=sc;j--){
            cout<<arr[er][j]<<" ";
            cnt++;
        }
        er--;
        if(cnt == n*m) break;

        for(int j=er;j>=sr;j--){
            cout<<arr[j][sc]<<" ";
            cnt++;
        }
        sc++;
        if(cnt == n*m) break;
    } 
    return 0;
}