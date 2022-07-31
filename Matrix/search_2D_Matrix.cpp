/*
Code by:Eeshan Chanpura
Created on: 30-12-2021 21:31
*/
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int t )
{
    int r=matrix.size();
    int c= matrix[0].size();
    if(r==0) return false;
    int r1=0, r2=r-1, mid;
    // check for target value row 
    while(r1 < r2)
    {
        mid = r1 + (r2-r1)/2;
        if(matrix[mid][c-1] < t) r1 = mid+1;
        else if(matrix[mid][0] > t) r2 = mid-1;
        else 
        {
            r1 =mid;
            break;
        }
    }

    int c1=0, c2= c-1;
    while(c1<=c2)
    {
        mid = c1+(c2-c1)/2;
        if(matrix[r1][mid] <t) c1=mid+1;
        else if(matrix[r1][mid] > t) c2 =mid-1;
        else return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat[0].size();j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    cout<<endl;
    cout<<boolalpha<<"Key value 3 , Found Status:"<<searchMatrix(mat,3);
    return 0;
}