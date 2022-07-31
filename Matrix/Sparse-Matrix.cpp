#include<iostream>
#include<bits/stdc++.h>
//#include<stdlib.h> ---- for using malloc, calloc function
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};
struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    int i;
    cout<<"Enter the dimensions: ";
    cin>>s->m>>s->n;
    cout<<"Enter the Total number of elements: ";
    cin>>s->num;
    //s->ele = (struct Element *)malloc(s->num*sizeof(struct Element)); ------for C
    s->ele = new Element[s->num];
    cout<<"Enter the non-zero elements: ";
    for(i=0;i<s->num;i++)
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
}
void display(struct Sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j)
                cout<<s.ele[k++].x<<" ";
            else    
                cout<<"0 ";
        }
        cout<<endl;
    }
}
struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    if(s1->n != s2->n && s1->m != s2->m)
        return NULL;
    sum= new Sparse;
    sum->ele= new Element[s1->num+s2->num];
    while(i<s1->num && j<s2->num)
    {
        // if s1 has smaller row(i) than s2 then store  s1 in sum
        if(s1->ele[i].i<s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++];
        // else if s2 has smaller row(i) than s1 then store  s2 in sum
        else if(s1->ele[i].i>s2->ele[j].i)
            sum->ele[k++]=s2->ele[j++];
        //now check for column
        else
        {
            // if s1 has smaller column(j) than s2 then store  s1 in sum
            if(s1->ele[i].j<s2->ele[j].j)
                sum->ele[k++]=s1->ele[i++];
            // else if s2 has smaller column(j) than s1 then store  s2 in sum
            else if(s1->ele[i].j>s2->ele[j].j)
                sum->ele[k++]=s2->ele[j++];
            // now if both(s1 & s2) are equal than add both the element
            else
            {
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
            }
        }
    }
    //now just print the remaining elements of s1
    for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
    //now just print the remaining elements of s2
    for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;

    return sum;
}
int main()
{
    struct Sparse s1,s2,*s3;
    cout<<"Enter First Matrix details\n ";
    create(&s1);
    cout<<"Enter Second Matrix details\n ";
    create(&s2);
    s3=add(&s1,&s2);
    cout<<"First Matrix\n";
    display(s1);
    cout<<"Second Matrix\n";
    display(s2);
    cout<<"Sum of Matrix\n";
    display(*s3);

    return 0;
}