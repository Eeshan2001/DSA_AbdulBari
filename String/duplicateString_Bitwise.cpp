#include <bits/stdc++.h>
using namespace std;

void Find_Duplicates(string A){
    int H=0; //variable to set each character's bit
    int x=0;

    for(int i=0;i<A.length();i++){  //loop through the given string
        x = 1;  //Start from least significant bit
        x = x << A[i] - 97; //leftshift by this no. of times

        if((x & H) > 0){    //perform bitwise AND (if set before - duplicate)
            cout << A[i] << " is a duplicate" << endl;
        }else{
            H =x | H;//perform bitwise OR (if not set before - set now)
        }
    }
}
int main(){
    string A = "finding"; 
    Find_Duplicates(A);
}