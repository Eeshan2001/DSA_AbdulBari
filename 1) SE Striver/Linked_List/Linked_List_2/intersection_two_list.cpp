/*
Code by:Eeshan Chanpura
Coded on: 04-08-2022 20:27
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data)
{
	struct node *p;
	p = new node; 
	p->data = data;   // First node
	p->next = NULL;
	return p;  
}

void Display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

/*
    Method-1: Using Stack
    - Traverse and push list 1 in stack1
    - Traverse and push lisy 2 in stack2
    - pop both the stack till s1.top() == s2.top()
    - store the address 
*/
node* getIntersection1(struct node*p, struct node *q)
{
    stack<node*> s1,s2;
    while(p)
    {
        s1.push(p);
        p=p->next;
    }
    while(q)
    {
        s2.push(q);
        q=q->next;
    }
    struct node *res=NULL;
    while(!s1.empty() && !s2.empty())
    {
        s1.pop();
        s2.pop();
        if(s1.top()==s2.top())
            res=s1.top();
        else
            return res;
    }
    return res;
}

/*
    Method-2:
    - Find Length of both LL; L1 and L2
    - Check the difference d = |L1-L2|
    - if(L1>L2) traverse List 1 for difference d 
    - else if(L2>L1) traverse List2 for difference d
    - Now we have same number of nodes left to traverse in each LL
    - Traverse each of them simultaneoulsy, untill we get List1 == List2
    - i.e. both pointers pointing to same node
*/

int length(node* t){
    int l=0;
    while(t){
        l++;
        t= t->next;
    }
    return l;
}

node* getIntersection2(struct node *p,struct node *q)
{
    int len1 = length(p);
    int len2 = length(q);
    if(!p || !q) return NULL;
    if(len1>len2)
    {
        int diff=len1-len2;
        while(diff)
        {
            p=p->next;
            diff--;
        }
    }
    else if(len2>len1)
    {
        int diff=len2-len1;
        while(diff)
        {
            q=q->next;
            diff--;
        }
    }

    // Now both nodes are at same distance from intersection point
    while(p!=q)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}

node* getIntersection3(struct node *p,struct node *q)
{
    node* a=p;
    node* b=q;
    while(a!=b){
        if(!a)
            a=q;
        else
            a=a->next;
        if(!b)
            b=p;
        else
           b=b->next;
    }
    return a;
}

int main(){
    struct node *p,*q,*intersection;
    p = newNode(1);
	p->next = newNode(2);
	p->next->next = newNode(3);
	p->next->next->next = newNode(4);
	p->next->next->next->next = newNode(5);
    intersection = p->next->next->next->next;
	p->next->next->next->next->next = newNode(6);
	
	q = newNode(7);
	q->next = newNode(8);
	q->next->next = intersection;

    cout<<"First Linked List is: ";
    Display(p);
    cout<<"Second Linked List is: ";
    Display(q);    

    cout<<"The intersection point using stack method is "<<getIntersection1(p,q)->data;
    cout<<"\nThe intersection point using difference method is "<<getIntersection2(p,q)->data;
    cout<<"\nThe intersection point using Method-3 is "<<getIntersection3(p,q)->data;
    return 0;
}