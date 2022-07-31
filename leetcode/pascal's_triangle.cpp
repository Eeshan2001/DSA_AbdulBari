/*
Code by:Eeshan Chanpura
Created on: 29-12-2021 21:16
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal(int numRows)
{
    vector<vector<int>> ans(numRows);
    for(int i=0;i<numRows;i++)
    {
        ans[i].resize(i+1);
        ans[i][0]=ans[i][i]=1;

        for(int j=1;j<i;j++)
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
    }
    return ans;
}

int main(){
    int n=5;
    vector<vector<int>> res = pascal(n);
    for(int i=0; i< res.size(); i++)
    {
        for(int j=0; j< res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}