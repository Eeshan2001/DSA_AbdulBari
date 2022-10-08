/*
Code by:Eeshan Chanpura
Coded on: 09-08-2022 20:45
*/
#include<bits/stdc++.h>
using namespace std;


// Brute Force O(n^2)
int countPlatforms(vector<int>& at, vector<int>& dt){
    int n = at.size();
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
           if((at[i]>=at[j] && at[i]<=dt[j]) || (at[j]>=at[i] && at[j]<=dt[i]))
               count++;
        ans=max(ans,count); //updating the value
    }
    return ans;
}

// Optimized O(nlogn)
int countPlatforms2(vector<int>& at, vector<int>& dt){
    int n = at.size();
    sort(at.begin(),at.end());
    sort(dt.begin(),dt.end());
    int platform = 1, result = 1;
    int i = 1, j = 0;
    while(i < n && j < n){
        if(at[i] <= dt[j]){
            platform++; i++;
        }
        else{ platform--;j++;}
        result = max(result,platform);
    }
    return result;
}
int main(){
    vector<int> arr{900,945,955,1100,1500,1800};
    vector<int> dep{920,1200,1130,1150,1900,2000};
    cout<<"Minimum number of Platforms required: "<<countPlatforms(arr,dep)<<endl;
    return 0;
}