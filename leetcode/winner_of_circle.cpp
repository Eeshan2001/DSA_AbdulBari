/*
Code by:Eeshan Chanpura
Cooded on: 01-06-2022 19:51
*/
#include<bits/stdc++.h>
using namespace std;
// Method 1 : Recursive
int helper(int n,int k){
    if(n==1)
        return 0;
    return (helper(n-1,k)+k)%n;
}

int findWinner(int n,int k){
    return helper(n,k)+1;
}
// Method 2 : Iterative
int findWinner2(int n,int k){
    int ans=0;
    for(int i=1;i<=n;++i){
        ans = (ans+k)%i;
    }
    return ans+1;
}

int main(){
    int n=5,k=2;
    cout<<"Recursive ans: "<<findWinner(5,2)<<"\n";
    cout<<"Iterative ans: "<<findWinner2(5,2);
    return 0;
}