/*
Code by:Eeshan Chanpura
Cooded on: 03-04-2022 17:21
*/
#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
    
        ++i;
        --j;
    }
    return true;
}

bool valid_palindrome(string s){
    int i=0;
    int j = s.length()-1;
    while(i<j){
        if(s[i]!=s[j])
            return (is_palindrome(s,i,j-1) || is_palindrome(s,i+1,j));
        ++i;
        --j;
    }
    return true;
}

int main(){
    string s="abac";
    cout<<boolalpha<<valid_palindrome(s);
    return 0;
}