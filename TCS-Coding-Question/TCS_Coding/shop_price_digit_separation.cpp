/*
Code by:Eeshan Chanpura
Coded on: 21-08-2022 19:30
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int sum=0;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            string temp="";
            while(isdigit(str[i])){
                temp+= str[i];
                i++;
            }
            sum+= stoi(temp); 
            temp="";
        }
    }
    cout<<sum;

    return 0;
}