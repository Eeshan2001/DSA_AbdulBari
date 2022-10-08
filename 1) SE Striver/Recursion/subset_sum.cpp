/*
Code by:Eeshan Chanpura
Coded on: 12-09-2022 19:15

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.
             in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2].
             [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

*/

#include<bits/stdc++.h> 
using namespace std;

// Iteration 
   vector<int> subsetSums(vector<int> arr, int N)
   {
       int n=N;
       // Write Your Code here
       vector<int> ans;
       for(int i=0; i<pow(2,N); i++)
       {
           int sum=0;
           for(int j=0; j<n; j++)
           {
               if(i&(1<<j))
               {sum+=arr[j];}
           }
           ans.push_back(sum);
       }
       
       return ans;
   }

// Using Recursion
void helper(int inx, int sum, vector<int>& arr, int n, vector<int>& sumSubset){
    if(inx == n){
        sumSubset.push_back(sum);
        return;
    }
    // pick next index
    helper(inx+1, sum+arr[inx], arr, n, sumSubset);
    // Do not pick next index
    helper(inx+1, sum, arr, n, sumSubset);
}
vector<int> subsetSums2(vector<int> arr, int N){
    vector<int> sumSubset;
    helper(0,0,arr,N,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}
int main()
{
    int N;cin>>N;
    vector<int> arr(N);
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
    vector<int> ans = subsetSums2(arr,N);
    sort(ans.begin(),ans.end());
    for(auto sum : ans)
        cout<< sum<<" ";
    cout<<endl;
   return 0;
}