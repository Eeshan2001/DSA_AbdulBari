/*
Code by:Eeshan Chanpura
Cooded on: 29-07-2022 20:54
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<int> repeat_missing(vector<int> nums){
    unordered_map<int,bool> mp;
    vector<int> ans;
    for(auto i:nums){
        if(mp.find(i)==mp.end())
            mp[i]=true;
        else
            ans.push_back(i); // repeating number
    }

    for(int i=1;i<nums.size();i++)
        if(mp.find(i)==mp.end())
            ans.push_back(i); //missing number
    
    return ans;
}

// Method-2: using maths
vector<int> repeat_missing_2(vector<int> nums){
    lli  len = nums.size();
    lli  S = (len * (len+1))/2;
    lli  P = (len * (len+1) * (2*len+1))/6;
    lli  repeat =0, missing = 0;
    for(int i=0;i<len;i++){
        S -= (lli) nums[i];  // S=X-Y
        P -= (lli) nums[i]* (lli) nums[i]; //P= X^2 - Y^2
    }
    missing = (S+ P/S)/2;
    repeat = missing - S;
    vector<int> ans;
    ans.push_back(repeat);
    ans.push_back(missing);
    return ans;
}

int main(){
    vector<int> nums{1,3,3,5,4};
    vector<int> ans= repeat_missing(nums);
    cout<< "\nRepeating number: "<<ans[0]<<" Missing number: "<<ans[1];
    vector<int> res= repeat_missing_2(nums);
    cout<< "\nRepeating number: "<<res[0]<<" Missing number: "<<res[1];
    return 0;
}