/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 17:45
*/
//      RECURSION
#include<bits/stdc++.h>
using namespace std;

int check_HSL(string s, string ans, int index){
    if(ans == "HSL") return 1;
    if(ans.length() > 3) return 0;
    if(index >= s.length()) return 0;

    int cnt=0;
    for(int i=index;i<s.length();i++)
        cnt = cnt + check_HSL(s,ans+s[i],i+1);
    return cnt;
}
int main(){
    string s; cin>>s;
    cout<<check_HSL(s,"",0);
    return 0;
}