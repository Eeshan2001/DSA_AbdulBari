/* You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

   A row i is weaker than a row j if one of the following is true:

   The number of soldiers in row i is less than the number of soldiers in row j.
   Both rows have the same number of soldiers and i < j.
   Return the indices of the k weakest rows in the matrix ordered from weakest to strongest. */
/*
Code by:Eeshan Chanpura
Cooded on: 27-03-2022 18:17
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for (int i = 0; i < mat.size(); ++i) 
            mat[i].push_back(i);
        sort(mat.begin(),mat.end());
        vector<int> res(k);
        int n=mat[0].size()-1;
        for (int i=0;i<k;i++)
            res[i]=mat[i][n];
        return res;
    }

int main(){
    vector<vector<int>> mat= {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int k=3;
    vector<int> ans=kWeakestRows(mat,k);
    for (auto it:ans)
        cout<<it<<" "; 
    return 0;
}