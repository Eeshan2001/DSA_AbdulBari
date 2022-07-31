#include<iostream>
using namespace std;

void towerOfHanoi(int n,int A,int B,int C)
{
    if(n>0){
        towerOfHanoi(n-1,A,C,B);
        cout<<"("<<A<<","<<C<<")"<<"->";
        towerOfHanoi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    cout<<"Enter No. of Disk :";
    cin>>n;
    towerOfHanoi(n,1,2,3);
}