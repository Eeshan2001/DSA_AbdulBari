/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 00:03
*/
#include<bits/stdc++.h>
using namespace std;

int length_of_longest_Substring(string s){
    map<char,int> mp;
    int start = 0 , end = 0;
    int maxLength = 0;
    for(end=0;end<s.length();end++){
        if(mp.find(s[end]) != mp.end())
            start = max(start, mp[s[end]]+1);
        mp[s[end]] = end;
        maxLength = max(maxLength, end-start+1);
    }
    return maxLength;
}
int main(){
    string s = "abcaabcdaabb";
    cout<<length_of_longest_Substring(s);
    return 0;
}