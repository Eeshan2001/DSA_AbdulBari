/*
Code by:Eeshan Chanpura
Cooded on: 29-07-2022 20:22
*/
#include<bits/stdc++.h>
using namespace std;

// Method-1: Gap method
void merge_using_gap(int arr1[],int arr2[], int n, int m){
    int gap=ceil((float)(n+m)/2);
    
    while(gap>0){
        int i=0, j=gap;
        while( j < (n+m) ){
            if(j<n && arr1[i]>arr1[j])
                swap(arr1[i],arr1[j]);
            else if(j>=n && i<n && arr1[i] > arr2[j-n])
                swap(arr1[i],arr2[j-n]);
            else if(j>=n && i>=n && arr2[i-n]>arr2[j-n])
                swap(arr2[i-n],arr2[j-n]);
            
            i++;j++;
        }
        if(gap==1) 
            gap=0;
        else 
            gap=ceil((float)gap/2);
    }

}

// Method-2: Merge using intersion sort
void merge_using_intertion_sort(int arr1[],int arr2[], int n, int m){
    for (int i = 0; i < n; i++) {
        // take first element from arr1 
        // compare it with first element of second array
        // if condition match, then swap
        if (arr1[i] > arr2[0]) {
            swap(arr1[i],arr2[0]);
        }

        // then sort the second array
        // put the element in its correct position
        // so that next cycle can swap elements correctly
        int first = arr2[0];
        // insertion sort is used here
        int k;
        for ( k = 1; k < m && arr2[k] < first; k++) {
            arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
    }
}

int main(){
    int arr1[] = {1,4,7,8,10};
    int arr2[] = {2,3,9};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge_using_gap(arr1, arr2, 5, 3);
    cout << "Merge using gap \n After merge:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge_using_intertion_sort(arr1, arr2, 5, 3);
    cout << "Merge using insertion sort \n After merge:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}