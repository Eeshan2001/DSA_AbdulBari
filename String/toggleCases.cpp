#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"Enter String : ";
    cin>>s;
    for(int i=0; s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90) s[i] +=32;    // from uppercase to lowerase
        else if(s[i]>='a' && s[i]<=122) s[i] -=32; // from lowercase to uppercase
    }
    cout<<"Toggled cases is: "<<s;
    return 0;
}