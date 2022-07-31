#include<iostream>
using namespace std;

class Element
{
    public:
        int i;
        int j;
        int x;
};
class Sparse
{
    private:
        int m;
        int n;
        int num;
        Element *ele;
    public:
        Sparse(int m,int n,int num)
        {
            this->m=m;
            this->n=n;
            this->num=num;
            ele=new Element[this->num];
        }
        ~Sparse()
        {
            delete [] ele;
        }
        // friend function is used to globally declare any function
        //-----------Instead of using Add func use + operator manually-------------------
        Sparse operator+(Sparse &s);
        //-----------Instead of using read func use cin operator manually-------------------
        friend istream & operator>>(istream &is,Sparse &s);
        //-----------Instead of using display func use cout operator manually-------------
        friend ostream & operator<<(ostream &os,Sparse &s);
};

istream & operator>>(istream &is,Sparse &s)
{
    cout<<"Enter non-zero elements";
    for(int i=0;i<s.num;i++)
    cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    return is;
}
 
ostream & operator<<(ostream &os,Sparse &s)
{
    int k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if(s.ele[k].i==i && s.ele[k].j==j)
                cout<<s.ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &s)
{
    int i,j,k;

    if(m!=s.m || n!=s.n)
        return Sparse(0,0,0);
    Sparse *sum=new Sparse(m,n,num+s.num);
    i=j=k=0;
    while(i<num && j<s.num)
    {
        // if s1 has smaller row(i) than s2 then store  s1 in sum
         if(ele[i].i<s.ele[j].i)
            sum->ele[k++]=ele[i++];
        // else if s2 has smaller row(i) than s1 then store  s2 in sum
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++]=s.ele[j++];
        //now check for column
        else
        {
            // if s1 has smaller column(j) than s2 then store  s1 in sum
            if(ele[i].j<s.ele[j].j)
                sum->ele[k++]=ele[i++];
            // else if s2 has smaller column(j) than s1 then store  s2 in sum
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++]=s.ele[j++];
            // now if both(s1 & s2) are equal than add both the element
            else
            {
                sum->ele[k]=ele[i];
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
            }
        }
    }
    //now just print the remaining elements of s1
    for(;i<num;i++)sum->ele[k++]=ele[i];
    //now just print the remaining elements of s2
    for(;j<s.num;j++)sum->ele[k++]=s.ele[j];
    sum->num=k;
    return *sum;
}

int main()
{
    int a1,b1,c1;
    cout<<"Enter first matrix dimensions: ";
    cin>>a1>>b1;
    cout<<"Enter Total number of Non-Zero elements: ";
    cin>>c1;
    Sparse s1(a1,b1,c1);
    int a2,b2,c2;
    cout<<"Enter Second matrix dimensions: ";
    cin>>a2>>b2;
    cout<<"Enter Total number of Non-Zero elements: ";
    cin>>c2;
    Sparse s2(a2,b2,c2);

    cin>>s1;
    cin>>s2;
    Sparse sum=s1+s2;
    cout<<"First Matrix"<<endl<<s1;
    cout<<"Second MAtrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;

    return 0;
}