/*
Code by:Eeshan Chanpura
Created on: 01-01-2022 21:33
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
}*first = NULL;

void Create(int A[],int n)
{
    struct node *t,*last;
    first= new node;
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data = A[i];
        t->next = NULL;
        last->next =t;
        last=t;
    }
}

node* detectCycle(struct node *head)
{
    node *slow=head, *fast=head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
        {
            //return true i.e loop found
            slow=head;
            while(slow !=fast)
            {
                slow=slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    int A[]= {3,4,5,6,7};
    int n=sizeof(A)/sizeof(A[0]);
    struct node *t1,*t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    node *res = detectCycle(first);
    cout<<"Loop/Cycle starts at node "<<res->data;
    return 0;
}