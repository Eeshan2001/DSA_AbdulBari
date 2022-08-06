#include <bits/stdc++.h>
using namespace std;

int CountOccurrences(string str, string word)
{
	int count = 0;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    for(int i=0;i<word.length();++i) word[i] = tolower(word[i]);
    stringstream ss(str);
    string itr;
    while(ss >> itr){
        if(itr == word)
            count++;
    }
	return count;
}

int main()
{
	string str; getline (cin, str);
    string word; cin>>word;
	cout << CountOccurrences(str, word);
	return 0;
}

