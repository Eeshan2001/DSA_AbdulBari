/*
Code by:Eeshan Chanpura
Created on: 10-01-2022 21:41
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node *next;
};

template<class T>
class LinkedList
{
    private:
        Node<T> *first;
    public:
        LinkedList(){first = NULL;}
        LinkedList(T A[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, T x);
        T Delete(int index);
        int Length();
};

template<class T>
LinkedList<T>::LinkedList(T A[],int n)
{
    Node<T> *t,*last;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t = new Node<T>;
        t->data=A[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = first;
    while(first)
    {
        first=first->next;
        delete(p);
        p=first;
    }
}

template<class T>
void LinkedList<T>::Display()
{
    Node<T> *p=first;
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}

template<class T>
int LinkedList<T>::Length()
{
    Node<T> *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

template<class T>
void LinkedList<T>::Insert(int index,T x)
{
    Node<T> *t,*p=first;
    if(index <0 || index > Length())
        return;

    t=new Node<T>;
    t->data=x;
    t->next=NULL;

    if(index==0)
        {
            t->next=first;
            first=t;
        }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

template<class T>
T LinkedList<T>::Delete(int index)
{
    T x;
    Node<T> *p,*q=NULL;
    if(index < 1 || index > Length())
        return -1;
    if(index == 1)
    {
        p=first;
        first = first->next;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

int main(){
     
    int A[] = {3,5,6,7,8,9,10};
    int n=sizeof(A)/sizeof(A[0]);
    LinkedList<int> L1(A,n);
    L1.Delete(3);
    L1.Insert(6,15);
    cout<<L1.Length()<<endl;
    L1.Display();
    return 0;
}