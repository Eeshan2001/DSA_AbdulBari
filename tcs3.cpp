/*
Code by:Eeshan Chanpura
Coded on: 12-08-2022 21:49
*/
#include<bits/stdc++.h>
using namespace std;

class Product{
    private:
        string name,category;
        int n;
        map<pair<string,int>> brandProduct;
    public:
        Product(string na,string c, int a, map<pair<string,int>>& mp){
            name = na;
            category = c;
            n = a;
            brandProduct(mp);
        }
        void findCostliestProduct(){
            int currMax = 0; string itr;
            for(int i=0;i<n;i++){
                if(brandProduct[i].second > currMax){
                    currMax = brandProduct[i].second;
                    itr = brandProduct[i].first;
                }
            }
            cout<<"Costliest Product = "<<itr;
        }
};
int main(){
    string na;cin>>na;
    string c; cin>>c;
    int a; cin>>a;
    map<pair<string,int>> mp;
    for(int i=0;i<a;i++){
        string bName; cin>>bName;
        int price; cin>>price;
        mp.insert({bName,price});
    }
    Product obj (na,c,a,mp);
    obj.findCostliestProduct();

    return 0;
}