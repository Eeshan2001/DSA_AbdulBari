/*
Code by:Eeshan Chanpura
Coded on: 30-07-2022 21:02
*/
/*
Code by:Eeshan Chanpura
Coded on: 30-07-2022 20:59
*/
// a+b+c= 0
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target) {
    vector<int> ans;
    unordered_map<int,int>mp;
    for(int i=0;i < nums.size();i++){
        if(mp.find(target-nums[i]) != mp.end()){
            ans.push_back(nums[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]]=i;
    }
    return ans;
}
\
int main(){
    vector<int> nums{3,5,2,8,7};
    vector<int> res = twoSum(nums,9);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}