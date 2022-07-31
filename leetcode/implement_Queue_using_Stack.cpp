/*
Code by:Eeshan Chanpura
Created on: 03-01-2022 20:29
*/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> input, output;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // shift input to output 
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        int x = output.top();
        output.pop(); 
        return x; 
    }
    
    /** Get the front element. */
    int peek() {
        // shift input to output 
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top(); 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (input.empty() && output.empty());
    }
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
     
    int param_2 = obj->pop();
    cout<<"pop:"<<param_2<<"\n";
    int param_3 = obj->peek();
    cout<<"peek:"<<param_3<<"\n";
    bool param_4 = obj->empty();
    cout<<boolalpha<<param_4;
    return 0;
}