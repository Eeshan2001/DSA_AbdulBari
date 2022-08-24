/*
Code by:Eeshan Chanpura
Cooded on: 15-06-2022 18:45

refer question 3 of tcs preparation
Input : 
p1 = 30 (emp who solved 2nd and 2nd pb)
p2 = 26 (emp who solved 2nd and 3rd pb)
p3 = 28 (emp who solved 3rd and 1st pb)
q  = 14 (solved all three problem)
e  = 345 (Total employee)
r  = 43 (emp not participated)

Output:
126 (emp solve first pb)
246 (emp solved exactly 1/3)
*/
#include<bits/stdc++.h>
using namespace std;

void coding(int p1,int p2,int p3, int q,int e,int r){
     int ans_2 = e-r+2*q-p1-p2-p3;
     int x = ans_2/3;
     int ans_1  = x+q+p1-q+p3-q;
     cout<<ans_1<<endl;
     cout<<ans_2;
}
int main(){
    int p1,p2,p3,q,e,r;
    cin>>p1>>p2>>p3>>q>>e>>r;
    coding(p1,p2,p3,q,e,r);
    return 0;
}