/*
Code by:Eeshan Chanpura
Cooded on: 21-07-2022 12:11
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(string& s1, string& s2){
    return s1.size()>s2.size();
}
/* --------------- Method-1 -------------------------- */
string findThirdLargest1(string str[],int n ){
    sort(str,str+n,compare);
    return str[2];
}
/* --------------- Method-2 --------------------------- */
string findThirdLargest2(string str[],int n ){
    for(int i=0;i<n;++i){
        for(int j=1;j<n;++j){
            if(sizeof(str[i])>sizeof(str[j]))
                continue;
            else
                swap(str[i],str[j]);
        }
    }
    return str[2];
}
int main(){
    string str[]={"hello","world","coders"};
    int n = sizeof(str)/sizeof(str[0]);
    cout<<findThirdLargest1(str,n);
    cout<<findThirdLargest2(str,n);
    return 0;
}