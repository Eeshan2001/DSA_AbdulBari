/*
Code by:Eeshan Chanpura
Coded on: 04-10-2022 21:34
*/
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    return a<b?a:b;
}
int Minimum(int a, int b, int c) {
    return min(min(a,b),c);
}
int minDistance(char* X, char* Y)
{
    // Cost of alignment
    int cost = 0;
    int leftCell, topCell, cornerCell, i, j;
 
    int m = strlen(X)+1;
    int n = strlen(Y)+1;
 
    // T[m][n]
    int *T = (int *)malloc(m * n * sizeof(int));
 
    // Initialize table
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            *(T + i * n + j) = -1;
 
    // Set up base cases
    // T[i][0] = i
    for(i = 0; i < m; i++)
        *(T + i * n) = i;
 
    // T[0][j] = j
    for(j = 0; j < n; j++)
        *(T + j) = j;
 
    // Build the T in top-down fashion
    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            // T[i][j-1]
            leftCell = *(T + i*n + j-1);
            leftCell += 1; // deletion
 
            // T[i-1][j]
            topCell = *(T + (i-1)*n + j);
            topCell += 1; // insertion
 
            // Top-left (corner) cell
            // T[i-1][j-1]
            cornerCell = *(T + (i-1)*n + (j-1) );
 
            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            cornerCell += (X[i-1] != Y[j-1]); // may be replace
 
            // Minimum cost of current cell
            // Fill in the next cell T[i][j]
            *(T + (i)*n + (j)) = Minimum(leftCell, topCell, cornerCell);
        }
    }
 
    // Cost is in the cell T[m][n]
    cost = *(T + m*n - 1);
    free(T);
    return cost;
}

int main(){
    char* A = "Horse";
    char* B = "ros";
    cout<<strlen(A);
    cout<<minDistance(A,B);
    return 0;
}