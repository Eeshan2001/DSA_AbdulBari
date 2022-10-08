/*
Code by:Eeshan Chanpura
Cooded on: 24-07-2022 21:51
*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
    int maxi = INT_MIN, sum = 0;
    int s = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > maxi) {
            subarray.clear();
            maxi = sum; 
            subarray.push_back(s);
            subarray.push_back(i);

        }
        if (sum < 0) {
            sum = 0;
            s = i + 1;
        }
    }

    return maxi;
}

int main() {
    vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    vector <int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++) {
        cout << arr[i] << " ";
    }

}