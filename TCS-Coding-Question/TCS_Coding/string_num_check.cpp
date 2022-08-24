/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 17:25
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp; cin>>inp;
    string num="";
    string rem="";
    for(char i:inp){
        if(isdigit(i))
            num+=i;
        else
            rem+=i;
    }
    if(stoi(num) == rem.length())
        cout<<"TRUE "<<rem.length();
    else
        cout<<"FALSE "<<rem.length();
    return 0;
}