/*
Code by:Eeshan Chanpura
Cooded on: 03-04-2022 17:32
*/
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0; i<n;i++)
        while((nums[i]>=1 && nums[i]<=n) && (nums[i] != nums[nums[i]-1]))
            swap(nums[i],nums[nums[i]-1]);
        
    for(int i=0;i<n;i++)
        if(nums[i] != i+1)
            return i+1;
    return n+1;
}
int main(){
    vector<int> nums={3,4,-1,1};
    cout<<firstMissingPositive(nums);

    return 0;
}