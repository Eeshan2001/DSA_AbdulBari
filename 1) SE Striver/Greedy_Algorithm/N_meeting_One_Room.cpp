/*
Code by:Eeshan Chanpura
Coded on: 09-08-2022 18:43
*/
#include<bits/stdc++.h>
using namespace std;

void maxMeetings(vector<int>& start, vector<int>& end){
    vector<pair<int,int>> vec;
    int n = start.size();
    for(int i=0;i<n;i++)
        vec.push_back({end[i],i});
    sort(vec.begin(),vec.end());
    int temp=-1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(temp < start[vec[i].second]){
            ans.push_back(vec[i].second+1);
            temp = vec[i].first;
        }
    }
    cout<<"The order in which the meetings will be performed is: ";
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
}
int main() {
   //int n = 6;
   vector<int> start{1,3,0,5,8,5};
   vector<int> end  {2,4,5,7,9,9};
   maxMeetings(start, end);
   return 0;
}