/*
Code by:Eeshan Chanpura
Created on: 10-01-2022 18:48
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

bool isLOOP(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    while(p && q && q->next)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
            return true;
            // p=f;
            // while(p != q)
            // {
            //     p=p->next;
            //     q=q->next;
            // }
            // return p;
    }
    return false;
}

int main(){
    int A[]={3,5,6,8,9,10,15};
    int n=sizeof(A)/sizeof(A[0]);
    Create(A,n);
     
    //Operation for loop
    struct node *t1,*t2;
    t1=first->next->next->next;
    t2=first->next->next->next->next->next->next;
    t2->next=t1;
    cout<<boolalpha<<isLOOP(first);
    // struct node *t3 = isLOOP(first);
    // cout<<"Loop Starts at node "<<t3->data;     
    return 0;
}