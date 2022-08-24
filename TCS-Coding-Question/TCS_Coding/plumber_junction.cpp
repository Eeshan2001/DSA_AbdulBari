/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 13:44
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,R;
    cin>>N>>M>>R;
    int input[N], output[M];
    for(int i=0;i<N;i++)
        cin>>input[i];
    for(int i=0;i<M;i++)
        cin>>output[i];
    int s_inp = 0, s_out = 0;
    s_inp = accumulate(input,input+N,s_inp)-(R*N);
    s_out = accumulate(output,output+M,s_out)-(R*M);
    if(s_inp == s_out)
        cout<<"BALANCED";
    else if (s_inp > s_out)
        cout<<-(s_inp-s_out+R);
    else
        cout<< s_out-s_inp+R;
    return 0;
}