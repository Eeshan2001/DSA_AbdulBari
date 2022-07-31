/*
Code by:Eeshan Chanpura
Cooded on: 08-04-2022 17:45
*/
#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> res(stones.begin(),stones.end());
    while(res.size()>1){
        int y=res.top();  res.pop();
        int x=res.top();  res.pop();
        if(x!=y) res.push(y-x);
    }
    return res.empty() ? 0:res.top();
}
int main(){
    vector<int> stones = {2,7,4,1,8,1};
    cout<<"res:"<<lastStoneWeight(stones);
    return 0;
}