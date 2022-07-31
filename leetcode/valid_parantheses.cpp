/*
Code by:Eeshan Chanpura
Created on: 03-01-2022 18:14
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) 
{
        stack<int> st;
        for (int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                st.push('(');
            else if (s[i] == '[')
                st.push('[');
            else if (s[i] == '{')
                st.push('{');
            
            if(s[i] == ')')
            {
                if(st.empty() || st.top() !='(')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == ']')
            {
                if(st.empty() || st.top() !='[')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == '}')
            {
                if(st.empty() || st.top() !='{')
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
}
int main(){
    string s="{()[]}";
    cout<<"Valid Paranthese Status: "<<boolalpha<<isValid(s);
    return 0;
}