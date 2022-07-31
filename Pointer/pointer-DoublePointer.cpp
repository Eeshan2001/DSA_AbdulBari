/*
Code by:Eeshan Chanpura
Created on: 28-01-2022 20:07
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int var=789;
    int *ptr1 = &var;
    int **ptr2 = &ptr1;
    cout<<"var "<<var<<endl;
    cout<<"single pointer "<<*ptr1<<endl;
    cout<<"Double pointer "<<**ptr2<<endl;

    cout<<"Var address "<<&var<<endl;
    cout<<"ptr1 address "<<&ptr1<<endl;
    cout<<"ptr2 address "<<&ptr2<<endl;

    return 0;
}