#include<iostream>
using namespace std;

//Normal Recursion method
int fact(int n){
    if(n==0)return 1;
    return fact(n-1)*n;
}
int ncr(int n,int r){
    int num,den;
    num=fact(n);
    den=fact(r)*fact(n-r);
    return num/den;
}

//Pascal's Triangle Method
int NCR(int n,int r){
    if(n==r || r==0) return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}

int main()
{
    int n,r;
    cout<<"Enter n term :";
    cin>>n;
    cout<<"Enter r term :";
    cin>>r;
    cout<<"Value of "<<n<<"C"<<r<<" by normal method is :"<<ncr(n,r);
    cout<<"\nValue of "<<n<<"C"<<r<<" by pascal's triangle method is :"<<NCR(n,r);
}