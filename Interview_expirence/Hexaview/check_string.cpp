#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// bool canFormPalindrome(string str)
// {
// 	// Create a count array and initialize all
// 	// values as 0
// 	int count[NO_OF_CHARS] = { 0 };

// 	// For each character in input strings,
// 	// increment count in the corresponding
// 	// count array
// 	for (int i = 0; str[i]; i++)
// 		count[str[i]]++;

// 	// Count odd occurring characters
// 	int odd = 0;
// 	for (int i = 0; i < NO_OF_CHARS; i++) {
// 		if (count[i] & 1)
// 			odd++;

// 		if (odd > 1)
// 			return false;
// 	}

// 	// Return true if odd count is 0 or 1,
// 	return true;
// }

// string StringChallenge(string str){
//        //we extract every character of string string 2
//        if(canFormPalindrome(str)){
//             string string2="7edjk8ufa";
//             for(auto i:string2)
//             {
//             //we find char exit or not
//             while(find(str.begin(),str.end(),i)!=str.end())
//                 {
//                     auto itr = find(str.begin(),str.end(),i);
//                 //if char exit we simply remove that char
//                     str.erase(itr);
//                 }
//             }
//        }
//         return str;
// }

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}
string rearrangePalindrome(string str){
    if(isPalindrome(str))return str;
   unordered_map<char, int> hmap;
    for (int i = 0; i < str.length(); i++)
        hmap[str[i]]++;
 
    /* find the number of odd elements.
       Takes O(n) */
    int oddCount = 0;
    char oddChar;
    for (auto x : hmap) {
        if (x.second % 2 != 0) {
            oddCount++;
            oddChar = x.first;
        }
    }
 
    /* odd_cnt = 1 only if the length of
       str is odd */
    if (oddCount > 1
        || oddCount == 1 && str.length() % 2 == 0)
        return "-1";
 
    /* Generate first half of palindrome */
    string firstHalf = "", secondHalf = "";
    for (auto x : hmap) {
 
        // Build a string of floor(count/2)
        // occurrences of current character
        string s(x.second / 2, x.first);
 
        // Attach the built string to end of
        // and begin of second half
        firstHalf = firstHalf + s;
        secondHalf = s + secondHalf;
    }
 
    // Insert odd character if there
    // is any
    return (oddCount == 1)
               ? (firstHalf + oddChar + secondHalf)
               : (firstHalf + secondHalf);
}

string StringChallenge(string str){
    string res=rearrangePalindrome(str);
    res+="l5cqxj21a";
    for(int i=2;i<res.length();i+=3)
        res[i]='X';
    return res;
}
/* Driver code*/
int main()
{
	cout<<StringChallenge("anna");
	return 0;
}
