/*
Code by:Eeshan Chanpura
Coded on: 29-09-2022 12:29
*/
// Leetcode 658 : Find K Closest Element

/* An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b 
*/

#include<bits/stdc++.h>
using namespace std;

// Method -1 : Using Stable sort | T.C - O(nlogn + klogk)
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     stable_sort(begin(arr), end(arr), [x](const auto a, const auto b){
    //         return abs(a - x) < abs(b - x);   // sort by distance from x
    //     });
    //     arr.resize(k);                        // choose first k elements
    //     sort(begin(arr), end(arr));           // sort the output in ascending order before returning
    //     return arr; 
    // }
    
    // Method -2 : Using two pointer | T.C - O(n-k)
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     int left = 0, right  = arr.size()-1;
    //     while(right-left+1 > k){
    //         if(x-arr[left] <= arr[right]-x)
    //             right--;
    //         else left++;
    //     }
    //     return vector<int>(arr.begin()+left, arr.begin()+right+1);
    // }
    
    // Method -3 : Using binary search | T.C - O(logn + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = size(arr)-k;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(x-arr[mid] > arr[mid+k]-x)
                lo = mid+1;
            else hi = mid;
        }
        return vector<int>(begin(arr)+lo, begin(arr)+lo+k);
    }
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> ans = findClosestElements(arr,4,3);
    for(auto a:ans)
        cout<<a<<" ";
    return 0;
}