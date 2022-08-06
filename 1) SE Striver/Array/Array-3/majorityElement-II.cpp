/*
Code by:Eeshan Chanpura
Cooded on: 27-07-2022 22:46
*/
// Leetcode: Majority Element-II
#include <bits/stdc++.h>
using namespace std;

// Method-1: Using Map to store frequency
vector <int> majorityElementII(vector<int> nums){
  int n=nums.size();
  unordered_map < int, int > mp;
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    mp[nums[i]]++;
  }
  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }
  return ans;
}

// Method-2: Boyer's Moore Vooting ALgorithm
vector < int > majorityElementII(int nums[], int n) {
  int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}

int main() {
  int arr[] = {1,2,2,3,2};
  vector < int > majority;
  majority = majorityElementII(arr, 5);
  cout << "The majority element is ";

  for (auto it: majority) {
    cout << it << " ";
  }

  vector < int > maj;
  vector < int >nums{1,1,1,3,3,2,2,2};
  maj = majorityElementII(nums);
  cout << "\nThe majority element is ";

  for (auto it: maj) {
    cout << it << " ";
  }
}