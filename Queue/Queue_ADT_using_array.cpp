/*
Code by:Eeshan Chanpura
Cooded on: 27-03-2022 20:38
*/
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue(){front=rear=-1;size=10;Q=new int[size];}
        Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}
        void enqueue(int x);
        int dequeue();
        void Display();
};

void Queue::enqueue(int x){
    if(rear==size-1)
        cout<<"Queue Overflow";
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear)
        cout<<"Queue Underflow";
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.Display();
    q.enqueue(60);
    cout<<"\n"<<q.dequeue();
    cout<<"\n"<<q.dequeue();
    q.enqueue(60);
    q.Display();
    return 0;
}