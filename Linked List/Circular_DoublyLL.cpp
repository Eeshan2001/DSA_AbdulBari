/*
Code by:Eeshan Chanpura
Created on: 28-01-2022 19:34
*/
#include<bits/stdc++.h>
using namespace std;

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data = A[0]; 
    first->next = first->prev = first;
    last = first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data = A[i];
        t->next = last->next;
        t->prev=last;
        last->next = t;
        last=t;
    }
    first->prev = t;
}

void Display(struct node *h)
{
    struct node *z=h;
    cout<<"\n Forward order traversal: ";
    while(h->next != z)
        {
            cout<<h->data<<"->";
            h = h->next;
        }
        cout<<h->data<<endl;

    cout<<"\n Reverse order printing: ";
    node *last = first->prev;
    node *temp = last;
    while (temp->prev != last)
    {
        cout<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<temp->data<<endl;
}

int Length(struct node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=first);
    return len;
}

void Insert(struct node *p, int index, int x)
{
    struct node *t;
    if(index < 0 || index > Length(p))
        return;
    if(index == 0)
    {
        t = new node;
        t->data=x;
        if(!first)
        {
            first=t;
            first->next = first->prev = first;
            //return 1; //debug
        }
        else
        {
            t->next=first;
            t->prev =first->prev; 
            first->prev = first->prev->next = t;
            first=t;
            //return 2; //debug
        }
    }
    else  
    {
        t=new node;
        t->data=x;
        for(int i=0;i<index-1;i++) p = p->next;
        t->next=p->next;
        t->prev=p;
        // check if its last node then skip this step
        if(p->next) p->next->prev =t;
        p->next=t;
        //return 3; // debug
    } 
}

int Delete(struct node *p, int index)
{
    int x=-1;
    struct node *tem = first;
    if(index <0 || index > Length(p)) return x;
    if(index == 1)
    {
        while(p->next != first) p=p->next;
        x=first->data;
        if(first == p)
        {
            free(first);
            first=NULL;
        }
        else
        {
            first=first->next;
            if(first) first->prev = tem->prev;
            tem->prev->next = first;
        }
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

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(A[0]);
    Create(A,n);
    Display(first);
    Insert(first,0,15);
    Display(first); 
    Delete(first,6);
    Display(first);
    cout<<endl<<first->prev->data;
    // struct node *p=first;
    // while(p->next !=first) p=p->next;
    // cout<<endl<<p->next->data;
    return 0;
}