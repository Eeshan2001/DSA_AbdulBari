/*
Code by:Eeshan Chanpura
Coded on: 08-08-2022 20:25
*/
// Leetcode 26: remove duplicate from sorted array 
#include<bits/stdc++.h>
using namespace std;

// Method-1: Using Hashset
int removeDups(vector<int>& nums){
    set<int> s;
    for(int i=0;i<nums.size();i++) s.insert(nums[i]);
    int k= s.size();
    // replace starting of nums with all unique elements
    int i=0;
    for(int x:s){
        nums[i++] = x;
    }
    return k;
}

// Method-2: Using Two Pointer
int removeDups2(vector<int>& nums){
    int i=0;
    for(int j=1;j<nums.size();j++){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
int main(){
    vector<int> nums{1,1,1,2,2,3,3,3,4};
    cout<<"Total unique elements are : "<<removeDups2(nums);
    cout<<"\nArray is : ";
    for(auto it:nums) cout<<it<<" ";
    return 0;
}