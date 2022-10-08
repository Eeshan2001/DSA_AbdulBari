// Read from standard input and print to standard output
#include<bits/stdc++.h>
using namespace std;

int dotProduct(int s1[], int s2[],int n){
	int sum = 0;
  int i=n-1, j=0;
  while(j<n && i>=0)
    sum += (s1[i--]*s2[j++]);
  return sum;
}
int main()
{
  int n;
  cin>>n;
	int arr1[n],arr2[n];
  for(int i=0;i<n;i++) cin>>arr1[i];
  for(int i=0;i<n;i++) cin>>arr2[i];
  cout<<dotProduct(arr1,arr2,n);
  return 0;
}