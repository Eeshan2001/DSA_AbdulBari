#include<iostream>
using namespace std;

class upperTriangular {
    private:
        int n;
        int *A;
    public:
        upperTriangular(int n){
            this->n=n;
            A= new int[n];
        }
        ~upperTriangular(){
            delete []A;
        }
        void Set(int i,int j,int x);
        int Get(int i,int j);
        void Display();
        int GetDimension(){return n;}
};
void upperTriangular::Set(int i,int j,int x)
{
    if(i<=j)
        //for row-major
        A[n*(i-1)-(i-2)*(i-1)/2+j-i]=x;
        //for column-major
        //A[j*(j-1)/2+i-1]=x;
}
int upperTriangular::Get(int i,int j)
{
    if(i<=j)
        //for row-major
        return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
        //for column-major
        //return A[j*(j-1)/2+i-1];
    return 0;
}
void upperTriangular::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                //for row-major
                cout<<A[n*(i-1)-(i-2)*(i-1)/2+j-i]<<" ";
                //for column-major
                //cout<<A[j*(j-1)/2+i-1]<<" ";    
            else 
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    int d;
    cout<<"Enter the dimension: ";
    cin>>d;

    upperTriangular um(d);
    int x;
    cout<<"Enter All Elements: ";
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            um.Set(i,j,x);
        }
    }
    cout<<"Matrix : \n";
    um.Display();
    cout<<"Element at 3,4 index is: ";
    cout<<um.Get(3,4);
    return 0;
}