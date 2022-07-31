/*
Code by:Eeshan Chanpura
Created on: 28-02-2022 22:45
*/
#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int Top;
    int *S;
};

void Create(struct Stack *st)
{
    cout<<"Enter size of Array: ";
    cin>>st->size;
    st->Top = -1;
    st->S = new int[st->size];
}

void Display(struct Stack st)
{
    cout<<"\nStack Top->Bottom: ";
    for(int i=st.Top;i>=0;i--)
    {
        cout<<st.S[i]<<" ";
    }
}

void push(struct Stack *st,int x)
{
    if(st->Top == st->size-1)
        cout<<"Stack Overflow";
    else
    {
        st->Top++;
        st->S[st->Top] = x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->Top == -1)
        cout<<"Stack underflow";
    else
    {
        x = st->S[st->Top--];
        //st->Top--;
    }
    return x;
}

int peek(struct Stack st,int pos)
{
    int x=-1;
    if(st.Top-pos+1 <0)
        cout<<"Invalid Syntax";
    x=st.S[st.Top-pos+1];
    return x;

}

int isEmpty(struct Stack st)
{
    if(st.Top == -1)
        return 1; //i.e True
    return 0;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.Top];
    return -1;
}

int isFull(struct Stack st)
{
    return st.Top ==st.size-1;
}

int main(){
    struct Stack st;
    Create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    Display(st);
    cout<<endl<<peek(st,2);
    cout<<endl<<pop(&st);
    Display(st);
    return 0;
}