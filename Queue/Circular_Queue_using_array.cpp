/*
Code by:Eeshan Chanpura
Cooded on: 30-03-2022 21:34
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
        Queue(){front=rear=0;size=10;Q=new int[size];}
        Queue(int size){front=rear=0;this->size=size;Q=new int[this->size];}
        void enqueue(int x);
        int dequeue();
        void Display();
};

void Queue::enqueue(int x){
    if((rear+1)%size==front)
        cout<<"Queue Overflow";
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue::dequeue(){
    int x=-1;
    if(front==rear)
        cout<<"Queue Underflow";
    else{
        front = (front+1)%size;
        x=Q[front];
    }
    return x;
}

void Queue::Display(){
    int i=front+1;
    do{
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    }while(i != (rear+1)%size);
    cout<<endl;
}

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<endl;
    q.Display();
    q.enqueue(60);
    cout<<"\n"<<q.dequeue();
    cout<<"\n"<<q.dequeue();
    q.enqueue(60);
    cout<<endl;
    q.Display();
    return 0;
}