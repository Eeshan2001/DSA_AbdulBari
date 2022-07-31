/*
Code by:Eeshan Chanpura
Created on: 12-03-2022 19:53
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"stack is Full\n";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    struct Node *t;
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int stackTop()
{
    if(top)
        return top->data;
    return -1;
}

bool isEmpty()
{
    return top?false:true;
}

bool isFull()
{
    struct Node *t=new Node;
    bool r=t?false:true;
    free(t);
    return r;
}

int peek(int pos)
{
    Node *p=top;
    for (int i=0;p!=NULL && i<pos-1;i++)    
        p=p->next;
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

void Display()
{
    struct Node *p;
    p=top;
    cout<<"Stack Top-Bottom: ";
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    Display();
    cout<<pop();
    cout<<peek(2);
    cout<<stackTop();
    cout<<boolalpha<<isEmpty();
    cout<<boolalpha<<isFull();
    cout<<pop();
    cout<<pop();
    cout<<boolalpha<<isEmpty();
    cout<<boolalpha<<isFull();
    return 0;
}