/*
Code by:Eeshan Chanpura
Coded on: 29-07-2022 21:16
*/
/*
    for all i & j < size of array, if i < j 
                                   then you have to find pair (A[i],A[j]) 
                                   such that A[i] > A[j].

    Input Format: N = 5, array[] = {5,3,2,1,4}

    Result: 7

    Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
    (3,2), (3,1), (2,1) 
*/

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums,int left,int mid,int right)
{
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    vector<int> temp(nums.size());
    while((i <= mid-1) && (j <= right)){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = nums[i++];

    while(j <= right)
        temp[k++] = nums[j++];

    for(i = left ; i <= right ; i++)
        nums[i] = temp[i];
    
    return inv_count;
}

int merge_Sort(vector<int>& nums,int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(nums,left,mid);
        inv_count += merge_Sort(nums,mid+1,right);

        inv_count += merge(nums,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    vector<int> nums{5,3,2,1,4};
    int ans = merge_Sort(nums,0,nums.size()-1);
    cout<<"The total inversions are: "<<ans<<endl; 
    return 0;
}