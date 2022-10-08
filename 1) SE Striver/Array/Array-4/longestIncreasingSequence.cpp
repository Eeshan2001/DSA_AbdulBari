/*
Code by:Eeshan Chanpura
Coded on: 08-08-2022 18:28
*/
// Leetcode 300: Longest increasing sequence
#include<bits/stdc++.h>
using namespace std;

// Method-1: Using DP O(n2)
int lengthOfLIS(vector<int>& nums){
    int ans = 1;
    vector<int> dp(nums.size(),1);
    for(int i=1;i< nums.size();++i){
        for(int j=i-1;j>=0;j--){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i],dp[j]+1);
                ans = max(ans,dp[i]);
            }
        }
    }
    return ans;
}

// Method-2: Using Binary Search O(nlogn)
/*  Logic: 1) make empty vector res
           2) use lower bound to check number >= nums[i
           3) if(num[i] == res.end) push nums[i] i res
              else: 
                replace lowerbound iterator (res) with nums[i] 
*/
int lengthOfLIS2(vector<int>& nums){
    vector<int> res;
    for(auto it: nums){
        auto curr = lower_bound(res.begin(),res.end(),it);
        if(curr == res.end()) res.push_back(it);
        else
            *curr = it;
    }
    return res.size();
}

int main(){
    vector<int> nums{10,9,2,5,3,7,101,181};
    cout<<"Using DP: "<<lengthOfLIS(nums)<<endl;
    cout<<"Using Lower bound: "<<lengthOfLIS2(nums);
    return 0;
}