/*
Code by:Eeshan Chanpura
Coded on: 10-08-2022 21:32
*/
#include<bits/stdc++.h>
using namespace std;


bool comp( pair<int,int>& a, pair<int,int>& b){
    double r1 = (double) a.second/ (double) a.first;
    double r2 = (double) b.second/ (double) b.first;
    return r1 > r2;
}
double fractionalKnapsack(vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);
    int currWeight = 0;
    double finalValue = 0.0;
    for(int i=0; i< n;i++){
        if(currWeight+ items[i].first <= w){
            currWeight += items[i].first;
            finalValue += items[i].second;
        }
        else{
            int remain = w - currWeight;
            finalValue += ((double)items[i].second/(double) items[i].first) * (double)remain; 
            break;
        }
    }
    return finalValue;
}
int main(){
   int n = 3, w = 50;
   // items {weights,values}
   vector<pair<int,int>> items { {20,100},{10,60},{30,120} };
   double ans = fractionalKnapsack(items,n,w);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}