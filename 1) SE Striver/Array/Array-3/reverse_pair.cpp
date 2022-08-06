/*
Code by:Eeshan Chanpura
Coded on: 29-07-2022 22:06
*/
/* LEETCODE: 293 (HARD) 
  count total pair where : 
    0<i<j<nums.size() and nums[i] > 2*nums[j]
*/

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> & nums,int low, int mid, int high){
    int tot=0, j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j <= high && nums[i] > 2*nums[j]){
            j++;
        }
        tot += (j-(mid+1));
    }
    vector<int> t;
    int left = low, right=mid+1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right])
            t.push_back(nums[left++]);
        else
            t.push_back(nums[right++]);
    }
    while(left<=mid)
        t.push_back(nums[left++]);
    while(right<=high)
        t.push_back(nums[right++]);
    for(int i=low;i<=high;i++)
        nums[i] = t[i-low];
    return tot;
}

int mergeSort(vector<int> & nums,int low, int high){
    if(low >= high) return 0;
    int mid = (low+high)/2;
    int inv_count = mergeSort(nums,low,mid);
    inv_count += mergeSort(nums,mid+1,high);
    inv_count += merge(nums,low,mid,high);
    return inv_count;
}

int reversePairs(vector < int > & nums) {
  return mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums{1,3,2,3,1};
    cout<<reversePairs(nums);
    return 0;
}