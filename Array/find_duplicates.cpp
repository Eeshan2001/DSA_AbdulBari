/*
Code by:Eeshan Chanpura
Cooded on: 26-07-2022 13:21
*/
#include<bits/stdc++.h>
using namespace std;

set<int> find_duplicates(int arr[],int n){
    int i=0;
    while(i<n){
        if(arr[i]!= arr[arr[i]-1]){
            swap(arr[i],arr[arr[i]-1]);
        }
        else
            ++i;
    }
    set<int> res;
    for(int i=0;i<n;++i){
        if(arr[i]!= i+1)
            res.insert(arr[i]);
    }
    return res;
}
int main(){
    int array[]={1,3,4,1,2,5,1,5};
    int n=sizeof(array)/sizeof(array[0]);
    set<int> ans = find_duplicates(array,n);
    for(auto it: ans)
        cout<<it<<" ";
    return 0;
}