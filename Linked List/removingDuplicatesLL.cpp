/*
Code by:Eeshan Chanpura
Created on: 08-01-2022 19:54
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[], int n)
{
    int i;
    struct node *t,*last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next =t;
        last=t;
    }
}

void Display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void removeDuplicates(struct node *p)
{
    struct node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
 
int main()
{
    int A[]={3,3,5,5,7,10,10,15};
    int n=sizeof(A)/sizeof(A[0]);
    Create(A,n);
    cout<<"Before Removal: ";
    Display(first);
    removeDuplicates(first);
    cout<<endl;
    cout<<"After Removal: ";
    Display(first);
    return 0;
}