/*
Code by:Eeshan Chanpura
Created on: 23-01-2022 21:04
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*Head;

void Create(int A[],int n)
{
    struct node *t,*last;
    Head=new node;
    Head->data = A[0]; 
    Head->next = Head;
    last = Head;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last=t;
    }

}

void Display(struct node *h)
{
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    }while(h != Head);
    cout<<endl;
}

void RDisplay(struct node *h)
{
    static int flag=0;
    if(h != Head || flag == 0)
    {
        flag=1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag=0;
}

int Length(struct node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void Insert(struct node *p, int Index, int x)
{
    struct node *t;
    if(Index < 0 || Index > Length(p))
        return;
    if(Index == 0)
    {
        t = new node;
        t->data=x;
        if(Head == NULL)
        {
            Head=t;
            Head->next = Head;
        }
        else
        {
            while(p->next !=Head) p=p->next;
            t->next=Head;
            p->next=t;
            // Head = t doesn't matter because insert before first is same as insert after last
            Head = t; 
        }
    }
    else 
    {
        t=new node;
        t->data=x;
        for(int i=0;i<Index-1;i++) p = p->next;
        t->next=p->next;
        p->next=t;
    }
}

int Delete(struct node *p, int index)
{
    int x;
    struct node *q;
    if(index < 0 || index> Length(Head) || !p )
        return -1;
    if(index == 1)
    {
        while(p->next != Head) p =p->next;
        x=Head->data;
        if(Head == p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(int i=0;i<index-2;i++) p= p->next;
        q=p->next;
        x=q->data;
        p->next = q->next;
        free(q);
    }
    return x;

}

int main(){
    int A[] = {2,4,5,6,7,8,9};
    int n = sizeof(A)/sizeof(A[0]);
    Create(A,n);
    Display(Head);
    RDisplay(Head); 
    cout<<endl;
    cout<<"Length of LL: "<<Length(Head);
    cout<<endl;
    Insert(Head,0,15);
    Display(Head);
    cout<<endl;
    int a = Delete(Head,8);
    cout<<"Deleted item is: "<<a<<endl;
    Display(Head);
    
    return 0;
}