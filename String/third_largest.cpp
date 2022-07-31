/*
Code by:Eeshan Chanpura
Cooded on: 21-07-2022 12:11
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(string& s1, string& s2){
    return s1.size()>s2.size();
}

string findThirdLargest(string str[],int n ){
    sort(str,str+n,compare);
    return str[2];
}

int main(){
    string str[]={"hello","world","coders"};
    int n = sizeof(str)/sizeof(str[0]);
    cout<<findThirdLargest(str,n);
    return 0;
}