#include<iostream>
using namespace std;

int sum(int n){
    if(n==0)
    return 0;
    else
    return sum(n-1)+n;
}

int Isum(int n)
{
    int s=0,i;
    for(i=1;i<=n;i++)
        s=s+i;
    return s;
}
int Isum1(int n)
{
    return (n*(n+1))/2;
}
int main(){
    int x;
    cout<<"Enter the Natural number: ";
    cin>>x;
    cout<<"Sum of "<<x<<" numbers using recursion is: "<<sum(x);
    cout<<"\nSum of "<<x<<" numbers using simple logic is: "<<Isum1(x);
    cout<<"\nSum of "<<x<<" numbers uisng loop is: "<<Isum(x);
}