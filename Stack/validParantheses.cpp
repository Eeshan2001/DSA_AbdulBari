/*
Code by:Eeshan Chanpura
Cooded on: 13-03-2022 19:37
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]=='[')
            st.push(s[i]);
        else if(s[i]=='{')
            st.push(s[i]);

        if(s[i]==')'){
            if(st.empty() || st.top() !='(')
                return false;
            else    
                st.pop();
        }
        else if(s[i]==']'){
            if(st.empty() || st.top() !='[')
                return false;
            else    
                st.pop();
        }
        else if(s[i]=='}'){
            if(st.empty() || st.top() !='{')
                return false;
            else    
                st.pop();
        }
    }
    if(st.empty())
        return true;
    else    
        return false;
}

int main(){
    string s="{(a+b)*[c/(a+b)]}";
    cout<<boolalpha<<isValid(s);
    return 0;
}