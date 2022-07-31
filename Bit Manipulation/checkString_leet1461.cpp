/*
Code by:Eeshan Chanpura
Cooded on: 31-05-2022 20:12
*/
#include<bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k) {
    set<string> us;
    if(s.size()<k) return false;
    for(int i=0;i<s.size()-k;i++)
        us.insert(s.substr(i,k));
    for(auto it:us)
        cout<<it<<" ";
    return us.size()==1<<k;
}

int main(){
    cout<<boolalpha<<hasAllCodes("00110110",2);
    return 0;
}