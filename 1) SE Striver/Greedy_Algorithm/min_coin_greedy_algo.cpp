// C++ program to find minimum
// number of denominations
/*
Code by:Eeshan Chanpura
Coded on: 09-08-2022 20:13
*/
#include<bits/stdc++.h>
using namespace std;

// All denominations of Indian Currency
int deno[] = { 1, 2, 5, 10, 20,
			50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);

int findMin(int V)
{
	sort(deno, deno + n,greater<int>());

	// Initialize result
	vector<int> ans;

	// Traverse through all denomination
	for (int i = 0; i < n; ++i) {

		// Find denominations
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}

	// Print result
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
    return ans.size();
}

// Driver program
int main()
{
	int n = 93;
	cout << "Following is minimal"
		<< " number of change for " << n
		<< ": ";
	int ans=findMin(n);
    cout<<endl<<ans;
	return 0;
}
