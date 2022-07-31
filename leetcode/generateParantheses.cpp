/*
Code by:Eeshan Chanpura
Created on: 15-02-2022 21:59
*/
#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<string>& ans, string curr, int left, int right, int max) 
{
    if(curr.length() == max*2) {
        ans.push_back(curr);
        return;
    }
    if(left<max)
        backtrack(ans, curr+"(", left+1, right,max );
    if(right<left)
        backtrack(ans, curr+")", left, right+1,max); 
}

vector<string> generateParenthesis(int n) 
{
    vector<string> ans;
    string curr;
    backtrack(ans,curr,0,0,n);
    return ans;
} 
        
int main(){
    int n;
    cout<<"Enter max no for parathesis: ";
    cin>>n;
    vector<string> res = generateParenthesis(n); 
    for(auto i = 0; i < res.size(); i++)
        cout <<res[i] << " ";
    return 0;
}