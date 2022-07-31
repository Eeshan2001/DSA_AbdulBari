/*
Code by:Eeshan Chanpura
Created on: 28-12-2021 17:35
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
       
        for( auto i : s) {   
            int temp1 = count( nums1.begin(), nums1.end() , i);
            int temp2 = count( nums2.begin(), nums2.end() , i);
             
            int k = min(temp1, temp2);
            
            while(k-- > 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
int main()
{
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={1,2};
    cout<<"Vector 1: ";
    for (auto it = nums1.begin(); it != nums1.end(); ++it)
        cout << *it << " ";
    cout<<endl;
    cout<<"Vector 2: ";
    for (auto its = nums2.begin(); its != nums2.end(); ++its)
        cout << *its << " ";
    cout<<endl;
    cout<<"Intersection of two vector: ";
    vector<int> ans=intersect(nums1,nums2);
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
    return 0;
}
