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

int count_Nodes(struct node *p)
{
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}

/* Pseudo Code Reversing Element
    1. Declare Array 
    2. Insert p->data in A[i]
    2. Start insertig data in LL from last of Array
*/
void reverse1(struct node *p)
{
    struct node *q=p;
    int *A,i=0;
    A = new int[count_Nodes(p)];
    while(q)
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;i--;
    while(q)
    {
        q->data =A[i];
        q=q->next;
        i--;
    }
}

/* Psedo Code Reversing Links Slider Pointer Approach 
    1. take three p,q,r
        p=first q=NULL r=NULL
    2. increment r=q    q=p p=p->next
    3. now assign q->next = r
    4. first = q
*/
void reverse2(struct node *p)
{
    struct node *q=NULL, *r = NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

/* Pseudo Code Recursion */
void reverse3(struct node *q, struct node *p)
{
    if(p)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else 
        first=q;
}

int main()
{
    int A[]={3,5,7,10,15};
    int n=sizeof(A)/sizeof(A[0]);
    Create(A,n);
    Display(first);

    cout<<"\nMethod 1: Array ";
    reverse1(first);
    Display(first);

    cout<<"\nMethod 2: Slider Pointer ";
    reverse2(first);
    Display(first);

    cout<<"\nMethod 3: Using Recursion ";
    reverse3(NULL,first);
    Display(first);

    return 0;
}
 