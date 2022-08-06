/*
Code by:Eeshan Chanpura
Cooded on: 29-07-2022 20:50
*/
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  int freq[n + 1] = {0};
  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0)
      freq[arr[i]] += 1;
    else 
      return arr[i];
  }
  return 0;
}

int findDuplicate2(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
   cout << "The duplicate element is " << findDuplicate2(arr) << endl;
}