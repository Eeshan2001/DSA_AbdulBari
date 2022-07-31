/*
Code by:Eeshan Chanpura
Coded on: 30-07-2022 20:59
*/
// a+b+c= 0
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            //to remove any duplicate at the first number
            if(i>0 && nums[i]==nums[i-1])continue;
            int low=i+1, high = nums.size()-1, sum= -nums[i];
            while(low < high){
                if(nums[low]+ nums[high] == sum){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    //remove duplicate in the 2nd number
                    while(low<nums.size()-1 && nums[low]==nums[low+1])low++;    
                    //remove duplicate in the 3rd number
                    while(high>0 && nums[high]==nums[high-1])high--;                        
                    low++,high--;
                }
                else if(nums[low]+nums[high] < sum) low++;
                else 
                    high--;
            }
        }
        return ans;
    }

int main(){
    vector<int> nums{-1,0,-1,1,2,-4};
    vector<vector<int>> res = threeSum(nums);
    for(auto i:res)
    {
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}