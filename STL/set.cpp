/*
Code by:Eeshan Chanpura
Coded on: 15-08-2022 20:52
*/

#include <iostream>
#include<set>
using namespace std;

int main() {
	// your code goes here

    set<string> fruits = {"apple","mango","guava","banana","apple"};

    // int n=5;
    // while(n--){
    //     string fruit;
    //     cin>>fruit;
    //     fruits.insert(fruit);
    // }

    if(fruits.find("papaya") != fruits.end()){
        fruits.erase("papaya");
    }
    
    //Iterate using iterator
    for(set<string>::iterator it = fruits.begin(); it!= fruits.end(); it++ ){
        cout << *it <<endl;
    }
	return 0;
}

