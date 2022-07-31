/*
Code by:Eeshan Chanpura
Cooded on: 21-07-2022 12:28
*/
#include<bits/stdc++.h>
using namespace std;

string fizzBuzz(int num){
    string res="";
    for(int i=1;i<=num;++i){
        if(i%3==0)
            res+="Fizz ";
        else if(i%5==0)
            res+="Buzz ";
        else if(i%15==0)
            res+="FizzBuzz ";
        else
            res+= to_string(i)+" ";
    }
    return res;
}
int main(){
    cout<<fizzBuzz(8);
    return 0;
}