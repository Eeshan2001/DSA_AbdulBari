/*
Code by:Eeshan Chanpura
Cooded on: 15-06-2022 19:24

Input :
    N=3 (tree height)
    M=100 (profit per person)
    R=10 (percent to provide to supervisor)
Output :
    1 
expanation:
    100%10 = 10
    10%10 = 1   
    root will recieve (1%) 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,R;
    cin>>N>>M>>R;
    int i=0;
    while(i<N-1){
        M = (M*R)/100;
        ++i;
    }
    cout<<M;
    return 0;
}