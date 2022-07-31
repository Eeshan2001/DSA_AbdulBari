/*
Code by:Eeshan Chanpura
Cooded on: 24-07-2022 21:41
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
// Using recursion
long factorialNum(int number)
{
	if(number == 0 || number == 1)
	{
		return 1;
	}
	else
	{
		return number * factorialNum(number - 1);
	}
}
void pascalRecur(int number){
    for (int i = 0; i < number; i++)
	{
		for (int j = 0; j <= (number - i - 2); j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << factorialNum(i) / (factorialNum(j) * factorialNum(i - j)) << " ";
		} 
		cout << "\n";
	}
}
int main(){
    vector<vector<int>> res;
    res=generate(5);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    pascalRecur(5);
    return 0;
}