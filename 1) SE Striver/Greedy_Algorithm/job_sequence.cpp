/*
Code by:Eeshan Chanpura
Coded on: 10-08-2022 20:04
*/
#include<bits/stdc++.h>
using namespace std;


bool comparator(vector<int>& a, vector<int>& b){
    return (a[1] > b[1]);
}

pair<int,int> jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),comparator);
    int maxi = jobs[0][0];
    for (int i = 1; i < n; i++)
         maxi = max(maxi, jobs[i][0]);
    int slot[maxi + 1];
    for(int i=0;i<maxi+1;i++) 
        slot[i]=-1;
    
    int jobProfit = 0, countJobs = 0;

      for (int i = 0; i < n; i++) {
         for (int j = jobs[i][0]; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += jobs[i][1];
               break;
            }
         }
      }
    return {countJobs,jobProfit};
}

int main(){
    int n = 4;
    vector<vector<int>> jobs{{4,50},{1,10},{1,40},{1,30}};
    pair<int,int> p = jobScheduling(jobs);
    cout<<p.first<<" "<<p.second;
    return 0;
}