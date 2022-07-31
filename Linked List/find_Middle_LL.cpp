/*
Code by:Eeshan Chanpura
Created on: 29-01-2022 21:14
*/
#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
} 

void Display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}

void Middle_1()
{
    struct node *p,*q;
    p=q=first;;
    // while(q)
    // {
    //     q=q->next;
    //     if(q) q=q->next;
    //     if(q) p=p->next;
    // }
    while(q and q->next)
    {
        p=p->next;
        q=q->next->next;
    }
    cout<<"\nMiddle element of LL by tailing ptr method is: "<<p->data;
}
int Length(struct node *p)
{
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}

void Middle_2()
{
    struct node *p=first;
    int x=Length(first);
    int mid = floor(x/2);
    for(int i=0;i<mid;i++) p=p->next;
    cout<<"\nMiddle element of LL by Brute force is: "<<p->data;
}

void Middle_3()
{
    struct node *mid=first;
    struct node *p=first;
    int count=0;
    while(p)
    {
        //Update mid, when 'count' is odd number
        if(count & 1) mid=mid->next;
        count++;
        p=p->next;
    }
    if(mid) cout<<"\nMiddle element of LL by Counter ODD is: "<<mid->data;
}

int main(){
    int A[] = {10,20,30,40,50,60,70,80};
    int n=sizeof(A)/sizeof(A[0]);
    Create(A,n);
    Display(first);
    Middle_1();
    Middle_2();
    Middle_3();
    return 0;
}