/*
Code by:Eeshan Chanpura
Cooded on: 30-03-2022 21:57
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    Node *t = new Node;
    if(t==NULL) cout<<"Queue is Full";
    else{
        t->data=x;
        t->next=NULL;
        if(front == NULL) front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    Node *p;
    if(front==NULL) cout<<"Queue is Empty";
    else{
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}

void Display(){
    cout<<endl;
    struct Node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    cout<<dequeue();
    Display();
    return 0;
}