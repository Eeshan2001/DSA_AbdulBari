/*
Code by:Eeshan Chanpura
Coded on: 30-07-2022 20:59
*/
// a+b+c= 0
#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans = 0, diff = INT_MAX;
    for(int i=0;i<nums.size();i++){
        int start = i+1, end = nums.size()-1;
        while(start < end){
            if(nums[i]+nums[start]+nums[end] == target) return target;
            else if(abs(nums[i]+nums[start]+nums[end]-target) < diff){
                diff = abs(nums[i]+nums[start]+nums[end]-target);
                ans = nums[i]+nums[start]+nums[end];
            }
            else 
                (nums[i]+nums[start]+nums[end]>target) ? end--:start++;            
        }
    }
    return ans;
}

int main(){
    vector<int> nums{-1,2,1,-4};
    cout<<threeSumClosest(nums,1);
    return 0;
}