/*
Code by:Eeshan Chanpura
Coded on: 05-08-2022 21:58
*/
#include<bits/stdc++.h>
using namespace std;

void countVowels(string str){
    map<char,int,greater<int>> mp;
    for(int i=0;i<str.length();i++){
        if(tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' 
           || tolower(str[i]) == 'u' || tolower(str[i]) == 'o')
                mp[tolower(str[i])]++;
    }
    auto end =mp.end();
    end--; // end to second last;
    if(mp.size() > 0){
        cout<<"{";
        auto it = mp.begin();
        while(it != end){
            cout<<"\'"<<it->first<<"\'"<<":"<<it->second<<",";
            it++;
        }  
        cout<<"\'"<<it->first<<"\'"<<":"<<it->second;
        cout<<"}";
    }
    else
        cout<<"No vowels found.";
    
}

int main(){
    string str;
    getline(cin,str);
    countVowels(str);
    return 0;
}
