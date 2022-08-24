/*
Code by:Eeshan Chanpura
Coded on: 19-08-2022 19:17
*/
#include<bits/stdc++.h>
using namespace std;

bool superASCII(string s){
    map<char,int> mp;
    for(int i=0;i<s.length();i++)
        mp[s[i]]++;
    bool flag = true;
    
    for(int i=0;i<s.length();i++){
        if(mp[s[i]] != (s[i]-'a'+1)){
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    int T; cin>>T;
    while(T--){
        string s;
        cin>>s;
        if(superASCII(s))
            cout<<"Yes";
        else
            cout<<"No";
    }
    return 0;
}