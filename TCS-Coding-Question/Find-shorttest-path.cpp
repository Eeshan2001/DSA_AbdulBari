/* Input : n= 4
           n[i] = 100 ,200,300,250.
   Ouput : 100 200
   Input : n= 3
           n[i] = 100 ,100,100.
   Ouput : Equal
   If Input n < 2 print Invalid
*/
/*
Code by:Eeshan Chanpura
Cooded on: 14-06-2022 19:19
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10], counter=0,n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n<2) {cout<<"Invalid Output"; return 0;}
    sort(arr,arr+n);
    for(int i=0;i<n;++i){
        if(arr[i]==arr[0])
            counter++;
    }
    if(counter==n)
        cout<<"Equal";
    else{
        cout<<arr[0]<<" "<<arr[1];
    }
    return 0;
}