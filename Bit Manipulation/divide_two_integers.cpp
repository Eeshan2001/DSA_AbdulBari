/*
Code by:Eeshan Chanpura
Cooded on: 30-05-2022 14:15
*/
/********** APPROACH *************/
/* Steps:
    1) while we can subtract divisor from dividend (line21)
        ->if yes, double divisor
        ->increment count 
        ->check agin
    2) add count in res(line31)
    3) subtract temporary variable from dividend(line32)
*/
#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    if (dividend == -2147483648)
        if (divisor == 1) return -2147483648;
        else if (divisor == -1) return 2147483647;
    bool sign = (dividend >= 0 == divisor >= 0) ? true:false;
    long absdividend = abs(dividend);
    long absdivisor = abs(divisor);
    int res = 0;
    while(absdividend - absdivisor >= 0){
        int count = 0;
        while(absdividend - (absdivisor<<1<<count) >= 0 ){
            count++;
        }
        res += 1<<count;
        absdividend -= absdivisor<<count;
    }
    return sign? res:-res;
}

int main(){
    int a=10,b=3;
    cout<<divide(a,b);
    return 0;
}