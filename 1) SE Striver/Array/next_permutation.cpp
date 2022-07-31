/*
Code by:Eeshan Chanpura
Cooded on: 24-07-2022 20:39
*/
#include<bits/stdc++.h>
using namespace std;

// Method -1 : Brute force (recursive)
void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i= index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        recurPermute(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}
vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> ans;
    recurPermute(0,nums,ans);
    return ans;
}

// Method -2 : Optimal approach
void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
}
int main(){
    vector<int> num{1,2,3};
    nextPermutation(num);
    for(auto it:num)
        cout<<it;
    cout<<endl;
    // method-1: brute force
    vector<vector<int>> res=permute(num);
    cout << "All Permutations are" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}