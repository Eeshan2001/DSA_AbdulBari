/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 19:10
*/
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        set<int> rows;
        set<int> cols;
        
        for(int i = 0; i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                if(rows.count(i) || cols.count(j))
                    matrix[i][j]= 0;
        }
                 
                    
    }
int main(){
    vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
    cout<<"Before setting to zeroes: "<<endl;
    for(auto i: matrix){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    setZeroes(matrix);
    cout<<"After setting to zeroes: "<<endl;
    for(auto i: matrix){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}