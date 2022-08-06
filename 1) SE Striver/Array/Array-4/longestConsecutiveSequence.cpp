/*
Code by:Eeshan Chanpura
Coded on: 02-08-2022 20:58
*/
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> nums) {
    if(nums.size() == 0 ){
        return 0;
    }    
    sort(nums.begin(),nums.end());    
    int ans = 1;
    int prev = nums[0];
    int cur = 1;
        
    for(int i = 1;i < nums.size();i++){
        if(nums[i] == prev+1) cur++;
        //else if we find new sequence    
        else if(nums[i] != prev) cur = 1;
        prev = nums[i];
        ans = max(ans, cur);
    }
    return ans;
}
//Method -2 : Using hashset and Optimization
int longestConsecutive2(vector<int> nums){
    unordered_set<int> s(begin(nums), end(nums));
	int longest = 0;
	for(auto num : s) {
        // iterate till min value of longest sequence
        // to do so .. check if num-1 there if so then continue
        if(s.count(num - 1)) continue;
		int j = 1;
        // now we found min value . 
        // now check if num+1 exists  then j++;
		while(s.count(num + j)) j++;
		longest = max(longest, j);
	}
	return longest;
}

int main()
{
    vector<int> arr{100,3,200,4,1,2,5};
    int lon=longestConsecutive(arr);
    cout<<"The longest consecutive sequence is: "<<longestConsecutive(arr)<<endl;      
    cout<<"The longest consecutive sequence is: "<<longestConsecutive2(arr)<<endl;      
}