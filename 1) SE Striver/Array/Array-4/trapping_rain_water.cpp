/*
Code by:Eeshan Chanpura
Coded on: 08-08-2022 19:51
*/
#include<bits/stdc++.h>
using namespace std;

// Method-1: Better Solution using Prefix and Suffix sum
int trap_water(vector<int>& height){
    int n = height.size();
    int prefix[n], suffix[n];
    prefix[0] = height[0];
    // find prefix sum
    for(int i=1;i<n;i++)
        prefix[i] = max(prefix[i-1],height[i]);
    suffix[n-1] = height[n-1];
    for(int i=n-2; i>=0;i--)
        suffix[i] = max(suffix[i+1],height[i]);
    int waterTrapped = 0;
    for(int i=0;i<n;i++)
        waterTrapped += min(prefix[i],suffix[i]) - height[i];
    return waterTrapped;
}

// Method-2: Two Pointer Approach (left_max,right_max)
int trap_water2(vector<int>& height){
    int n=height.size();
    int left=0, right = n-1;
    int res=0;
    int left_max = 0, right_max = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= left_max)
                left_max = height[left];
            else
                res += left_max - height[left];
            left++;
        }
        else{
            if(height[right] >= right_max)
                right_max = height[right];
            else
                res += right_max - height[right];
            right--;
        }
    }
    return res;
}

int main(){
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Using Better Solution: "<<trap_water(height)<<endl;
    cout<<"Using Two pointer Solution: "<<trap_water2(height);
    return 0;
}