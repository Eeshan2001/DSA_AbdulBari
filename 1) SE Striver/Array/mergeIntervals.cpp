/*
Code by:Eeshan Chanpura
Cooded on: 29-07-2022 18:31
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}
int main(){
    vector<vector<int>>intervals {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = mergeInterval(intervals);
    for(auto i:res)
         cout << i[0] << " " << i[1] << "\n";
    return 0;
}