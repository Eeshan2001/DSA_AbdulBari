/*
Code by:Eeshan Chanpura
Coded on: 21-08-2022 18:38
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string cstr,res;
    getline(cin,cstr);
    for(int i=0;i<cstr.length();i++){
        if(cstr[i] >= 'A' && cstr[i] <= 'Z'){
            if(i!=0)
                res += " ";
            res+= tolower(cstr[i]);
        }
        else
            res += cstr[i];
    }
    cout<<res;
    return 0;
}