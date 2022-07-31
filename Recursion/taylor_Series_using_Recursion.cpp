#include<iostream>
using namespace std;

//Taylor Series normal formula
double taylor(int x,int n){
    static double p=1,f=1,r;
    if(n==0)
        return 1;
    else{
        r=taylor(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

//Taylor Series Horner’s Rule -----------------simplified formula for e^x
double taylor1(int x, int n)
{
    static double s=1;
    if(n==0)
        return s;
    s=1+x*s/n;
    return taylor1(x,n-1);
}

//Taylor Serie Iterative
double taylor2(int x, int n)
{
    double s=1;
    int i;
    double num=1;
    double den=1;
    for(i=1;i<=n;i++)
    {   
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main()
{
    int a,b;
    cout<<"Enter the x and n terms for Tayylor series e^x:";
    cin>>a>>b;
    cout<<"\nThe taylor series using normal form of e^"<<a<<" has value : "<<taylor(a,b);
    cout<<"\nThe taylor series using Horner's Rule of e^"<<a<<" has value : "<<taylor1(a,b);
    cout<<"\nThe taylor series Iterative of e^"<<a<<" has value : "<<taylor2(a,b);
}