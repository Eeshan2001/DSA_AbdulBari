#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
         string str=s;
         for(auto x:s){
             str=str.substr(1);
             str +=x;
             if(str==goal) return true;
         }
        return false;
    }
};

int main()
{
    Solution s1;
    string s="abcd";
    string goal="bcda";
    cout<<s1.rotateString(s,goal);
}