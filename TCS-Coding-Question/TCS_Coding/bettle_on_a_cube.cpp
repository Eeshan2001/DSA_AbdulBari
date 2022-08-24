/*
Code by:Eeshan Chanpura
Coded on: 20-08-2022 18:38
*/

// Difficult = High Nice question
#include<bits/stdc++.h>
using namespace std;

int start_x, start_y, start_z;
float distance(int x, int y, int z){
    float dist = 0.0;
    if(z == start_z && (x == start_x || y == start_y) && start_z != 0)
    {
        if(x != start_x)
            dist = (2*3.14*(abs(x-start_x)))/6.0;
        else
            dist = (2*3.14*(abs(y-start_y)))/6.0;
    }
    else
        dist= (int)(sqrt(pow(x-start_x,2) + pow(y-start_y,2)) + abs(z-start_z));
    
    start_x = x;
    start_y = y;
    start_z = z;
    return dist;
}

int main(){
    int n; cin>>n;
    float sum = 0.0;
    int arr[3*n];
    for(int i=0; i< 3*n; i++)
        cin>>arr[i];
    start_x = arr[0];
    start_y = arr[1];
    start_z = arr[2];
    for(int i=3;i<3*n; i=i+3)
        sum = sum + distance(arr[i],arr[i+1],arr[i+2]);
    cout<<fixed<<setprecision(2)<<sum;
    return 0;
}