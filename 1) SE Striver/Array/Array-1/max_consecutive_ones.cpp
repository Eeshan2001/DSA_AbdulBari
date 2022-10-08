/*
Code by:Eeshan Chanpura
Coded on: 08-08-2022 20:42
*/
#include<bits/stdc++.h>
using namespace std;


    int findMaxConsecutiveOnes(vector < int > & nums) {
      int cnt = 0, maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1)
          cnt++;
        else 
          cnt = 0;
        maxi = max(maxi, cnt);
      }
      return maxi;
    }

int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  cout << "The maximum  consecutive 1's are " << findMaxConsecutiveOnes(nums);;
  return 0;
}
