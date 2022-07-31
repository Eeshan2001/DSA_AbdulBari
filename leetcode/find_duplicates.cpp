/*
Code by:Eeshan Chanpura
Cooded on: 29-03-2022 20:29
*/
#include<bits/stdc++.h>
using namespace std;

int find_dups(vector<int> &nums){
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++){
        if(nums[i-1] == nums[i]){
            return nums[i];
            break;
        }
    }
    return 0;
}
int main(){
    vector<int> nums={1,3,4,2,2};
    cout<<find_dups(nums);
    return 0;
}