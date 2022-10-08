/*
Code by:Eeshan Chanpura
Coded on: 15-08-2022 20:49
*/
 #include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int arr[] = {20, 30, 40, 40, 40, 50, 100};
    int n = sizeof(arr) / sizeof(int);
    //Search in a sorted array
    int key;
    for(int i=0;i<n;i++){
        key = arr[i];
        cout<<key<<":"<<upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n,key) <<endl;
    }
    return 0;
}