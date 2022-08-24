//Smallest number whose digits multiplication is ‘N’
//Input : 10    Input : 13
//Output : 25   Output: Not Possible
/*
Code by:Eeshan Chanpura
Cooded on: 14-06-2022 18:45
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

void findSmallest(int num){
    int i, j = 0;
    // To store digits of result
    // in reverse order
    int res[MAX];
 
    // Case 1: If number is smaller than 10
    if (num < 10)
    {
        cout << num + 10;
        return;
    }
    // Case 2: Start with 9 and try every possible digit
    for (i = 9; i > 1; i--)
    {
        // If current digit divides n, then store all
        // occurrences of current digit in res
        while (num % i == 0)
        {
            num = num / i;
            res[j++] = i;
        }
    }
    // If n could not be broken
    // in form of digits (prime factors
    // of n are greater than 9)
    if (num > 10)
    {
        cout << "Not possible";
        return;
    }
    // Print the result array in reverse order
    for (i = j - 1; i >= 0; i--)
        cout << res[i];
}

int main(){
    findSmallest(10); cout<<endl;
    findSmallest(13); cout<<endl;
    findSmallest(150);
    return 0;
}