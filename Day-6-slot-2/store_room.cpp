/*
Code by:Eeshan Chanpura
Coded on: 24-08-2022 16:52
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,i,j,c;
    cin>>n1>>n2;
    int a[n1],b[n2];
    set<int> s;
    for (int i=0;i<n1;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i=0;i<n2;i++){
        cin>>b[i];
        s.insert(b[i]);
    }
    vector<int> v(s.begin(),s.end());
    c = s.size();
    if (c%2 == 1){
        c/=2;
        cout<<v[c];
    }
    else{
        n1=c/2;
        n2 = n1-1;
        float q = (v[n1]+v[n2])/2.0;
        cout<<q;
    }
    return 0;
}