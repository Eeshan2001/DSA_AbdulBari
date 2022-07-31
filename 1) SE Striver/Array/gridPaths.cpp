/*
Code by:Eeshan Chanpura
Cooded on: 28-07-2022 20:09
*/
#include<bits/stdc++.h>
using namespace std;

// Method-1: DP
int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp){
    if(i==(n-1) && j==(m-1)) return 1;
    if(i>=n || j>=m) return 0;
    if(dp[i][j] !=-1) return dp[i][j];
    else
        return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
}
int uniquePaths(int m,int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int num=countPaths(0,0,m,n,dp);
    if(n==1 && m==1)
        return num;
    return dp[0][0];

}

// Method-2: Using Combination
int uniquePaths2(int m, int n){
    int N=m+n-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;++i)   
        res=res*(N-r+i)/i;
    return (int)res;
}
int main(){
    int totalCount= uniquePaths(3,7);
    cout<<"The total number of Unique Paths using DP are: "<<totalCount<<endl;
    int totalCount2= uniquePaths2(3,2);
    cout<<"The total number of Unique Pasing Combination are: "<<totalCount2<<endl;
    return 0;
}