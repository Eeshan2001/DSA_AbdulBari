/*
Code by:Eeshan Chanpura
Cooded on: 26-03-2022 20:02
*/

#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else 
        return false;
}

int pre(char c){
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixTOPostfix(string s){
    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if(isOperand(c))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && pre(s[i]) <= pre(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    return result;
}

int evaluate_postfix(string s){
    stack<int> st;
    int x1,x2,r;
    for (int i=0;s[i]!='\0';i++){
        if (isOperand(s[i]))
            st.push(s[i]-'0');
        else{
            x2=st.top();st.pop();
            x1=st.top();st.pop();
            switch(s[i]){
                case '+': 
                    r=x1+x2;
                    break;
                case '-':
                    r=x1-x2;
                    break;
                case '*':
                    r=x1*x2;
                    break;
                case '/':
                    r=x1/x2;
                    break;
            }
            st.push(r);
        }
    }
    return st.top();
}
int main(){
    string infix;
    cout<<"Enter infix expresion: ";
    cin>>infix;
    string ans=InfixTOPostfix(infix);
    cout<<"Postfix expresion: "<<ans;
    cout<<"\nEvaluate postfix is : "<<evaluate_postfix(ans);
    return 0;
}