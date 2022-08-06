/*
Code by:Eeshan Chanpura
Coded on: 02-08-2022 22:18
*/
#include<bits/stdc++.h>
using namespace std;

// find largest subarray with sum=0
int max_Subarr_with_sum_Zero(vector<int> nums){
    // map storing current sum, index
    map<int,int> mp;
    int maxi=0, sum =0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(sum == 0 ) maxi = i+1;
        else {
            if(mp.find(sum) != mp.end())
                maxi = max(maxi, i-mp[sum]);
            else
                mp[sum]=i;
        }
    }
    return maxi;
}
int main(){
    vector<int> nums{15,-2,2,-8,1,7,10,23};
    cout<<max_Subarr_with_sum_Zero(nums);
    return 0;
}