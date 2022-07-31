#include<iostream>
#include<math.h>
using namespace std;

struct term 
{
    int coeff;
    int expo;
};

struct polynomial 
{
    int n;
    struct term *t;
};

void create(struct polynomial *p)
{
    int i;
    cout<<"\nEnter no. of terms: ";
    cin>>p->n;
    p->t = new term[p->n];
    cout<<"Enter coefficient and exponetial of terms: \n";
    for(i=0;i<p->n;i++)
    {
        cin>>p->t[i].coeff>>p->t[i].expo;
    }
}

void display(struct polynomial p)
{
    int i;
    for(i=0;i<p.n;i++)
        cout<<p.t[i].coeff<<"x^"<<p.t[i].expo<<"+";
    cout<<"\n";
}

long int evaluate(struct polynomial p, int x)
{
    long int sum=0;
    for(int i=0;i<p.n;i++)
    {
        sum+= p.t[i].coeff*pow(x,p.t[i].expo);
    }
    return sum;
}
struct polynomial * add(struct polynomial *p1,struct polynomial *p2)
{
    int i,j,k;
    i=j=k=0;
    struct polynomial *sum;
    sum = new struct polynomial;
    sum->t = new term[p1->n+p2->n];
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo>p2->t[j].expo)
            sum->t[k++]=p1->t[i++];
        else if(p1->t[i].expo < p2->t[j].expo)
            sum->t[k++]=p2->t[j++];
        else
        {
                sum->t[k].expo=p1->t[i].expo;
                sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
        }
    } 
    for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
    for(;j<p2->n;j++)sum->t[k++]=p2->t[j];
    sum->n=k;
    return sum;
}

int main()
{
    struct polynomial p;
    create(&p);
    cout<<"Polynomial is: \n";
    display(p);
    cout<<"\n-----------------Evaluation--------------------\n";
    int x;
    cout<<"Enter value of x: ";
    cin>>x;
    cout<<"Value of polynomial is: "<<evaluate(p,x);

    cout<<"\n------------------Addition-----------------\n";
    struct polynomial p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3=add(&p1,&p2);
    cout<<"First Polynomial :"<<endl;
    display(p1);
    cout<<"Second Polynomial:"<<endl;
    display(p2);
    cout<<"Addition of Both Polynomial"<<endl;
    display(*p3);
    return 0;
}