/*
Code by:Eeshan Chanpura
Coded on: 02-08-2022 18:47
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>&nums, int target){
    vector<vector<int>> res;
        if(nums.empty())
            return res;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int target_3 = target - nums[i];
            for(int j=i+1;j<n;j++){
                int target_2 = target_3 - nums[j];
                int front = j+1;
                int back = n-1;
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        
                        // skip duplicates for front i.e 3rd number
                        while(front<back && nums[front] == quad[2]) ++front;
                        
                        // skip duplicates for back i.e 4th number
                        while(front<back && nums[back] == quad[3]) --back;
                    }
                }
                // skip duplicates for j i.e 2nd number
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            // skip duplicates for i i.e 1st number
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
}

int main(){
    vector<int> nums{1,0,-1,0,-2,2};
    vector<vector<int>> res = fourSum(nums,0);
    for(auto i:res)
    {
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}