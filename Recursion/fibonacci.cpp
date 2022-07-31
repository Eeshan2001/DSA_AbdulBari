#include<iostream>
using namespace std;

//Iterative Method 
int fib(int n)
{
    int t0=0,t1=1,s=0,i;
    if(n<=1) return n;
    for(i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

//Normal Recursion
int rfib(int n)
{
    if(n<=1)
        return n;
    return rfib(n-2)+rfib(n-1);
}

//Fibonacci with Memiozation
//Declare Global Variable 
int F[10];

int mfib(int n)
{
    if(n<=1)
    {
        F[0]=0;
        F[1]=1;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
        F[n-2]=mfib(n-2);
        if(F[n-1]==-1)
        F[n-1]=mfib(n-1);
    
    F[n]=F[n-2]+F[n-1];
    return F[n-2]+F[n-1];
    }
}

int main()
{
    int i;
    for(i=0;i<10;i++)
    F[i]=-1;
    int n;
    cout<<"Enter the Fibonacci nth term :";
    cin>>n;
    cout<<"\nThe Fibonacci series value of "<<n<<"th term is : "<<fib(n);
    cout<<"\nThe Fibonacci series using Recursion value of "<<n<<"th term is : "<<rfib(n);
    cout<<"\nThe Fibonacci series using Memoization value of "<<n<<"th term is : "<<mfib(n);

    cout<<"\n\n The Fibonacci Series is: ";
    for(int i=0;i<=n;i++){
        cout<<F[i]<<" ";
    }
    return 0;
}