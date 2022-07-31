/*
Code by:Eeshan Chanpura
Coded on: 29-07-2022 21:59
*/

#include<bits/stdc++.h>
using namespace std;

// Method-1
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
 
// Method-2: Binary Exponential
double myPow2(double x, int n){
    double res=1;
    while(n){
        if(n%2)
            res= n>0 ? res*x : res/x;
        x=x*x;
        n/=2;
    }
    return res;
}

int main()
{
    cout<<myPow(2,10)<<endl;
    cout<<myPow2(3,10)<<endl;
}