/*
Code by:Eeshan Chanpura
Cooded on: 19-05-2022 21:22
Leetcode-48 : Rotate Image
Approach: first trnapose matrix
          Second reverse each row

Input: 1 | 2 | 3
       4 | 5 | 6
       7 | 8 | 9

Output: 7 | 4 | 1
        8 | 5 | 2
        9 | 6 | 3
*/

#include<bits/stdc++.h>
using namespace std;

void rotate_Image(vector<vector<int>>& mat){
    int n=mat.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(mat[i][j],mat[j][i]);
    for(int i=0;i<n;i++)
        reverse(mat[i].begin(),mat[i].end());
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before rorating 90* clockwise:\n";
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    rotate_Image(mat);
    cout<<"After rorating 90* clockwise:\n";
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat.size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}