/*
Code by:Eeshan Chanpura
Coded on: 18-08-2022 17:46
*/
#include<bits/stdc++.h>
using namespace std;

int * rotate_array(int arr[],int n, int k){
    int* temp = new int[n];
    k = k%n;
    for(int i=0;i<k;i++) temp[i] = arr[n-k+i];
    int index=0;
    for(int i=k;i<n;i++) temp[i] = arr[index++];
    return temp;

}

int main(){
    int n=5, k=2, arr[]={10,20,30,40,50};
    int* res = rotate_array(arr,n,k);
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    return 0;
}