/*
Code by:Eeshan Chanpura
Cooded on: 27-07-2022 22:56
*/
#include<bits/stdc++.h>
using namespace std;

int majorityElement_1(vector<int>& nums){
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
}
// Boyer's Moore Method 
int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
    }

int main(){
    vector<int> nums{1,1,1,3};
    cout<<majorityElement(nums)<<endl;
    cout<<majorityElement_1(nums);
    return 0;
}