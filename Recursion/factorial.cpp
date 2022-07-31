#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
    return 1;
    else
    return fact(n-1)*n;
}

int IFact(int n)
{
    int f=1,i;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main(){
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    cout<<"Factorial of "<<x<<" numbers using recursion is: "<<fact(x);
    cout<<"\nFactorial of "<<x<<" numbers uisng loop is: "<<IFact(x);
}