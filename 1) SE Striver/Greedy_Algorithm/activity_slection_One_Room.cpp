/*
Code by:Eeshan Chanpura
Coded on: 10-08-2022 22:01
*/
#include<bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {    
    vector<pair<int,int>> v;
    for(int i = 0; i<start.size(); i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int count = 1, end = v[0].first;
    for(int i = 1; i<start.size(); i++){
        if(v[i].second >= end){
            end = v[i].first;
            count++;
        }
    }
    return count;
}

int main() {
   //int n = 4;
   vector<int> start{1,6,2,4};
   vector<int> end  {2,7,5,8};
   cout<<maximumActivities(start, end);
   return 0;
}