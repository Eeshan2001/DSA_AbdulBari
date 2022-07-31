/*
Code by:Eeshan Chanpura
Created on: 27-02-2022 20:38
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
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout<<"Matix Before set to zeros: \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }   
        cout << endl;
    }
    setZeroes(matrix);
    cout<<"\nMatix After set to zeros: \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }   
        cout << endl;
    }
    return 0;
}