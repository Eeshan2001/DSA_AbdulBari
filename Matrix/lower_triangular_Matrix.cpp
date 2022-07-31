#include<iostream>
using namespace std;

class lowerTriangular {
    private:
        int n;
        int *A;
    public:
        lowerTriangular(int n){
            this->n=n;
            A= new int[n];
        }
        ~lowerTriangular(){
            delete []A;
        }
        void Set(int i,int j,int x);
        int Get(int i,int j);
        void Display();
        int GetDimension(){return n;}
};
void lowerTriangular::Set(int i,int j,int x)
{
    if(i>=j)
        //for row-major
        A[i*(i-1)/2+j-1]=x;
        //for column-major
        //A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}
int lowerTriangular::Get(int i,int j)
{
    if(i>=j)
        //for row-major
        return A[i*(i-1)/2+j-1];
        //for column-major
        //return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    return 0;
}
void lowerTriangular::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
                //for row-major
                cout<<A[i*(i-1)/2+j-1]<<" ";
                //for column-major
                //cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";    
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

    lowerTriangular lm(d);
    int x;
    cout<<"Enter All Elements: ";
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            lm.Set(i,j,x);
        }
    }
    cout<<"Matrix : \n";
    lm.Display();
    cout<<"Element at 2nd index is: ";
    cout<<lm.Get(2,2);
    return 0;
}