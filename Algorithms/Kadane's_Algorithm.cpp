/*
Code by:Eeshan Chanpura
Created on: 27-12-2021 18:51
*/
#include<bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& nums)
{
    int endIndex=0;
    if(nums.size()==0) cout<<"Empty Array";
    int sub_max=nums[0];
    int sub_including_current=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        sub_including_current=max(sub_including_current+nums[i],nums[i]);
        // Check if sub_including_current is greater
        // than sub_max
        if (sub_including_current > sub_max) {
            sub_max = sub_including_current;
            endIndex = i;
        }
    }
    int startIndex = endIndex;
        int globalMax= sub_max;
        // Traverse in left direction to
        // find start Index of subarray
        while (startIndex >= 0) {
            globalMax -= nums[startIndex];
            if (globalMax == 0)
                break;
            // Decrement the start index
            startIndex--;
        }
        // Printing the elements of
        // subarray with max sum
        cout<<"\nMax Sub Array is: ";
        for (int i = startIndex;i <= endIndex;i++) {
            cout<<nums[i]<<" ";
        }

     cout<<"\nMax of Sub array is: "<<sub_max;
}

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Array is: ";
    for(auto it:nums)
    {
        cout<<it<<" ";
    }
    maxSubArray(nums);
    return 0;
} 