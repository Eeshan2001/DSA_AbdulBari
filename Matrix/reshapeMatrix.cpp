/*
Code by:Eeshan Chanpura
Created on: 29-12-2021 18:48
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reshapeMatrix(vector<vector<int>>& mat, int r, int c)
{
    if(mat.size()*mat[0].size() != r*c) return mat;
    int row=0;
    int col=0;
    vector<vector<int>> ans(r,vector<int> (c));
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            ans[row][col++]=mat[i][j];
            if(col == c)
            {
                row++;
                col=0;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> inp1 = {{1,2},{3,4}};
    vector<vector<int>> res = reshapeMatrix(inp1,1,4);
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