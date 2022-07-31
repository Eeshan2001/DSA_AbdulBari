/*
Code by:Eeshan Chanpura
Created on: 12-03-2022 20:20
*/
#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        int peek(int pos);
        void Display();
};

void Stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stak is Full\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop()
{
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else
    {
        x=top->data;
        Node *t=top;
        top=top->next;
        free(t);
    }
    return x;
}

int Stack::peek(int pos){
    Node *p=top;
    for (int i=0;p!=NULL && i<pos-1;i++)    
        p=p->next;
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

void Stack::Display()
{
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.Display();
    cout<<stk.pop();
    cout<<endl<<stk.peek(2);
    return 0;
}