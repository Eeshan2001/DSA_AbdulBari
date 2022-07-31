// Leetcode 576: Out of Boundary Paths
// Topic : DP Recursion and Memoization
/*
Code by:Eeshan Chanpura
Cooded on: 16-07-2022 13:57
*/
#include<bits/stdc++.h>
using namespace std;

int dp[51][51][51];
int mod = 1e9+7;

long dfs(int m,int n, int N,int i,int j){
    // if out of grid then add 1
    if(i>=m || j>=n || i<0 || j<0) return 1;
    if(N==0)return 0;
    // if already present in dp then don't go to recursion just return if
    if(dp[i][j][N]!=-1) return dp[i][j][N];
    long res=0;
    res += dfs(m,n,N-1,i-1,j);
    res += dfs(m,n,N-1,i+1,j);
    res += dfs(m,n,N-1,i,j-1);
    res += dfs(m,n,N-1,i,j+1);
    return dp[i][j][N] = res % mod;
}
int findPaths(int m,int n, int maxMove, int startRow, int startColumn){
    memset(dp,-1,sizeof(dp));
    return dfs(m,n,maxMove,startRow,startColumn);
} 
int main(){
    cout<<findPaths(2,2,2,0,0);
    return 0;
}