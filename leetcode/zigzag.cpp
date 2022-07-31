/*
Code by:Eeshan Chanpura
Created on: 12-03-2022 21:42
*/
#include<bits/stdc++.h>
using namespace std;
// Function for zig-zag Concatenation
string zigZag(string s, int n)
{
    // Check is n is less
    // or equal to 1
    if (n <= 1 || n>s.length())
    {
        return s;
    }
    string result = "";
    // Iterate rowNum from 0 to n - 1
    for (int rowNum = 0; rowNum < n; rowNum++)
    {
        int i = rowNum;
        bool up = true;
        // Iterate i till s.length() - 1
        while (i < s.length())
        {
 
            result += s[i];
 
            // Check is rowNum is 0 or n - 1
            if (rowNum == 0 || rowNum == n - 1)
            {
                i += (2 * n - 2);
            }
            else
            {
                if (up)
                {
                    i += (2 * (n - rowNum) - 2);
                }
                else
                {
                    i += rowNum * 2;
                }
                up ^= true;
            }
        }
    }
    return result;
}
 
// Driver Code
int main()
{
    string str = "PAYPALISHIRING";
    int n =3;
    cout<< zigZag(str, n);
}
 