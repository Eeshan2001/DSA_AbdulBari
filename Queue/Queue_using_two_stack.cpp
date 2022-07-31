/*
Code by:Eeshan Chanpura
Cooded on: 31-03-2022 21:02
*/
#include<bits/stdc++.h>
using namespace std;

struct Queue{
    private:
        stack<int> s1,s2;
    public:
        void enQueue(int x){
            s1.push(x);
        }
        int deQueue(){
            int x=-1;
            if(s1.empty() && s2.empty())
                cout<<"Queue is Empty";
            if(s2.empty())
            {
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            x=s2.top();
            s2.pop();
            return x;
        }
};
int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}