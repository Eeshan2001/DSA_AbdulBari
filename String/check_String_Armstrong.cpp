/*
Code by:Eeshan Chanpura
Cooded on: 03-05-2022 16:27
*/
#include<iostream>
#include<math.h>
using namespace std;

bool isArmstrong(int n){
    int originaln,r=0;
    // count number of digits
    for(originaln = n; originaln != 0; ++r) 
       originaln/= 10;

    int temp = n;
    double tot = 0;
  
    // Traverse each digit
    while (temp) {
        int itr = temp % 10;
        tot = tot + pow(itr,r);
        temp = temp / 10;
    }
    // If satisfies Armstrong condition
    if ((int)tot == n)
        return true;
    else
        return false;
}

int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.length();i++){
        sum += s[i];
    }
    bool res=isArmstrong(sum);
    if(res)
        cout<<"Interesting";
    else
        cout<<"Not Interesting";
    return 0;
}