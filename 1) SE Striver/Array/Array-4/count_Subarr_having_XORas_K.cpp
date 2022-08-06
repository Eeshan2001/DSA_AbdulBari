/*
Code by:Eeshan Chanpura
Coded on: 02-08-2022 22:24
*/
#include<bits/stdc++.h>
using namespace std;

int count_XOR_K(vector<int> nums, int k){
    map<int,int> freq;
    int cnt=0, xorr=0;
    for(auto it:nums){
        xorr ^= it;
        if(xorr == k) cnt++;
        if(freq.find(xorr^k) != freq.end())
            cnt += freq[xorr^k];
        freq[xorr]+=1;
    }
    return cnt;
}

int main(){
    vector<int> nums{4,2,2,6,4};
    cout<<count_XOR_K(nums,6);
    return 0;
}