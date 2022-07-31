// A C++ program to illustrate Caesar Cipher Technique
#include <iostream>
using namespace std;

// This function receives text and shift and
// returns the encrypted text
string StringChallenge(string str, int num)
{
	string result = "";

	// traverse text
	for (int i=0;i<str.length();i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(str[i]))
			result += char(int(str[i]+num-65)%26 +65);

	// Encrypt Lowercase letters
	else
		result += char(int(str[i]+num-97)%26 +97);
	}
    result+="l5cqxj21a";
    for(int i=2;i<result.length();i+=3)
        result[i]='X';
    return result;
	// Return the resulting string
}

// Driver program to test the above function
int main()
{
	string text="Hello";
	int s = 4;
	cout << "Text : " << text;
	cout << "\nShift: " << s;
	cout << "\nCipher: " << StringChallenge(text, s);
	return 0;
}
