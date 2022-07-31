/*
Code by:Eeshan Chanpura
Created on: 09-12-2021 21:20
*/

#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char> &s)
{
    // Techique used - Swapping
    for (int i = 0; i < s.size() / 2; i++)
    {
        int t = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = t;
    }
}
int main(){
    vector<char> s={'h','e','l','l','o'};
    reverseString(s);
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}