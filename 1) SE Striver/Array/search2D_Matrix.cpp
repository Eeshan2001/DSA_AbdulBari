/*
Code by:Eeshan Chanpura
Coded on: 29-07-2022 21:25
*/
#include<bits/stdc++.h>
using namespace std;

// Method-1: Using Binary Search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int n= matrix.size(), m=matrix[0].size();
    int low=0, high=(n*m)-1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(matrix[mid/m][mid%m]==target)
            return true;
        matrix[mid/m][mid%m] < target ? low=mid+1: high=mid-1;
    }
    return false;
}

// Method-2: Another Aproach
bool searchMatrix_2(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(), n=matrix[0].size(),r=0,c=n-1;
    while(r<m && c>=0){
        if(matrix[r][c]==target)
            return true;
        else{
            matrix[r][c] > target ? c--:r++;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<boolalpha<<searchMatrix(matrix,13)<<endl;
    cout<<boolalpha<<searchMatrix_2(matrix,23);
    return 0;
}