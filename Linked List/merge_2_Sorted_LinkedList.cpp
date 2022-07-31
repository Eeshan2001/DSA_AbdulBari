/*
Code by:Eeshan Chanpura
Created on: 09-01-2022 20:33
*/
#include<bits/stdc++.h>
using namespace std;
/*
Code by:Eeshan Chanpura
Created on: 08-01-2022 21:37
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

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

void Create2(int B[], int n1)
{
    int i;
    struct node *t,*last;
    second = new node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for(i=1;i<n1;i++)
    {
        t = new node;
        t->data = B[i];
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

void concat(struct node *p, struct node *q)
{
    third = p;
    while(p->next)
    {
        p=p->next;
    }
    p->next=q;
}

void mergeLL(struct node *p, struct node *q)
{
    struct node *last;
    if(p->data < q->data)
    {
        third=last = p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last = q;
        q=q->next;
        third->next=NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if(p) last->next=p;
    if(q) last->next=q;
}

int main()
{
    int A[]={10,20,30,40,50};
    int B[]={5,152,252,352,452};
    int n=sizeof(A)/sizeof(A[0]);
    int n1=sizeof(B)/sizeof(B[0]);
    Create(A,n);
    Create2(B,n1);
    cout<<"First: ";
    Display(first);
    cout<<"\nSecond: ";
    Display(second);
    // cout<<"\n Concatinated: ";
    // concat(first,second);
    // Display(third);

    cout<<endl;
    mergeLL(first,second);
    cout<<"Mergeing Two Sorted Linked List: ";
    Display(third);
    return 0;
}
 
 