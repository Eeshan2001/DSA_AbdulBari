/*
Code by:Eeshan Chanpura
Coded on: 23-09-2022 12:57
*/
#include<bits/stdc++.h>
using namespace std;

    // decimal to binary
    // string binary(int x){
    //     //finding the binary form of the number and converting it to string.
    //     string s = bitset<64> (x).to_string();
        
    //     //Finding the first occurrence of "1" to strip off the leading zeroes.
    //     const auto loc1 = s.find('1');
        
    //     if(loc1 != string::npos)
    //         return s.substr(loc1);
        
    //     return "0";
    // }
    int numberOfBits(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans; 
    }
int main(){
    cout<<concatenatedBinary(12);
    return 0;
}