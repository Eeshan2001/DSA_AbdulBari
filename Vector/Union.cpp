/*
Code by:Eeshan Chanpura
Created on: 28-12-2021 20:51
*/
#include<bits/stdc++.h>
using namespace std;

void printUnion(vector<int> a,vector<int> b)
{
    set<int> mp;
    for(auto it:a)
        mp.insert({it});
    for(auto i:b)
        mp.insert({i});
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout<<*itr<<" ";
}

int main(){
    vector<int>a={1,2,3,8,8,9,2,5,1,6};
    vector<int>b={2,6,9,10,1,4,5,3,2,1};
    printUnion(a,b);
    return 0;
}