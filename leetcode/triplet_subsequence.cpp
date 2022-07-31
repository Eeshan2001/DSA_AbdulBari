/*
Code by:Eeshan Chanpura
Cooded on: 21-05-2022 19:47
*/
#include<bits/stdc++.h>
using namespace std;
 
bool increasingTriplet(vector<int>& nums) {
    int a=INT_MAX;
    int b=INT_MAX;
    for(auto x: nums){
        if(x<=a)
            a=x;
        else if(x<=b)
            b=x;
        else
            return true;
    }
    return false;
}
int main(){
    vector<int> nums={5,4,3,2,1};//{2,1,5,0,4,6}
    cout<<boolalpha<<increasingTriplet(nums);
}