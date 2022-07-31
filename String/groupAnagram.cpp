/*
Code by:Eeshan Chanpura
Created on: 27-02-2022 20:47
*/
#include<bits/stdc++.h>
using namespace std;

/* Group Anagram
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/ 
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<string>>mp;
    for(string s:strs)
    {
        string t=s;
        sort(t.begin(),t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto s:mp)
    {
        ans.push_back(s.second);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    cout<<"Input Strings: ";
    for(auto it:strs)
        cout<<it<<" ";
    vector<vector<string>> res = groupAnagrams(strs);
    cout<<"\nAfter Grouping Anagram: ";
    for (int i=0; i < res.size(); i++)
    {
        for (int j=0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }   
        cout << endl;
    }
    return 0;
}  