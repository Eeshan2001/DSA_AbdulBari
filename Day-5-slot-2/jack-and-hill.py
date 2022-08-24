a=input()
b=input()
for i in b:
    a=a.replace(i,'')
print(a)

# #include <bits/stdc++.h>
# using namespace std;

# int main() {
#     string a,b;
#     cin>>a;
#     cin>>b;
    
#     string c = " ";
#     for(int i=0; i< a.length();i++){
#         for(int j=0; j< b.length()-1;j++){
#             if(a[i]==b[i])
#             continue;
#             else
#             c+=a[i];
#         }
#     }

    
#     cout<< c<< ”\n”;
#     return 0;
# }