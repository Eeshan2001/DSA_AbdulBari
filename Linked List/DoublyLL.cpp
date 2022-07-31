/*
Code by:Eeshan Chanpura
Created on: 27-01-2022 19:21
*/
#include<bits/stdc++.h>
using namespace std;

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[], int n)
{
    struct node *t,*last;
    first=new node;
    first->data = A[0];
    first->next=first->prev = NULL;
    last=first; 

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data = A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct node *p)
{
    while (p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}

int Length(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(struct node *p,int index,int x)
{
    struct node *t;
    if(index<0 || index> Length(p)) return;

    if(index==0)
    {
            t=new node;
            t->data=x;
            t->next=first;
            t->prev = NULL;
            first->prev=t;
            first=t;
    }
    else
    {
        t=new node;
        for(int i=0;i<index-1;i++) p=p->next;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        // check if its last node then skip this step
        if(p->next) p->next->prev =t;
        p->next=t;
    }
}

int Delete(struct node *p,int index)
{
    //struct Node *q;
    int x=-1;
    if(index < 1 || index > Length(p))
        return x;
    if(index==1)
    {
        first=first->next;
        if(first) first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=0; i<index-1 ;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct node *p)
{
    struct node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        //iterate 
        p=p->prev;
        if(p!= NULL && p->next==NULL)
            first=p;
    }
    
} 

int main(){
    int A[]={10,20,30,40,50};
    int n=sizeof(A)/sizeof(A[0]);
    Create(A,n);
    Display(first);
    cout<<"\n Length of Doubly LL is :"<<Length(first);
    cout<<endl;
    Insert(first,2,25);
    Display(first);
    cout<<endl;
    Delete(first,2);
    Display(first);
    cout<<endl;
    Reverse(first);
    Display(first);
    return 0;
}