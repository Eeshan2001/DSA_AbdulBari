/*
Code by:Eeshan Chanpura
Cooded on: 24-07-2022 21:21
*/
#include<bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
    
        cout<<a<<endl; 
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 

int main(){
    int intp = 123;
    string ans=to_string(intp);
    permute(ans,0,ans.size()-1);
    return 0;
}