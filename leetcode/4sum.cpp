/*
Code by:Eeshan Chanpura
Cooded on: 17-03-2022 18:26
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& num, int target){
    vector<vector<int>> res;
    if(num.empty())
        return res;
    int n = num.size();
    sort(num.begin(),num.end());

    for(int i=0;i<n;i++){
        int target_3 = target - num[i]; 
        for(int j=i+1;j<n;j++){
            int target_2 = target_3 - num[j];
            int front = j+1;
            int back = n-1;
            while(front < back){
                int two_sum = num[front] + num[back];
                if (two_sum < target_2) front++;
                else if (two_sum > target_2) back--;
                else{
                    vector<int> quadruplet(4,0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    res.push_back(quadruplet);

                    // Processing the duplicates of number 3 i.e front
                    while (front < back && num[front] == quadruplet[2]) ++front;
                    
                    // Processing the duplicates of number 4 i.e back
                    while (front < back && num[back] == quadruplet[3]) --back;
                }
            }
            // Processing the duplicates of number 2 i.e j
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
        }
        // Processing the duplicates of number 1 ie. i
        while (i + 1 < n && num[i + 1] == num[i]) ++i;
    }
    return res;
}

int main(){
    vector<int> v{1,0,-1,0,-2,2};
    
    vector<vector<int>> sum=fourSum(v,0);
    cout<<"The unique quadruplets are"<<endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
    return 0;
}