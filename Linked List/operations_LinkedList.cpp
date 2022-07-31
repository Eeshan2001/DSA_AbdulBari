#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
} 

void Display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}

void recursive_Display(struct node *p)
{
    //To Display LL in forward order
    if(p)
    {
        cout<<p->data<<"->";
        recursive_Display(p->next);
    }
    //Display's the LL in reverse order
    // if(p)
    // {
    //     recursive_Display(p->next);
    //     cout<<p->data<<"->";
    // }
} 

int count_Nodes(struct node *p)
{
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int recursive_count_Nodes(struct node *p)
{
    if(p)
        return recursive_count_Nodes(p->next)+1;
    else
        return 0;
}

int sum(struct node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int recursive_Sum(struct node *p)
{
    if(p==0)
        return 0;
    else 
        return recursive_Sum(p->next)+p->data;
}

int max(struct node *p)
{
    int m= INT32_MIN;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int rec_Max(struct node *p)
{
    int x=INT16_MIN;
    if(p==0)
        return x;
    x=rec_Max(p->next);
    return x>p->data ? x:p->data;
}

struct node * Lsearch(struct node *p,int key)
{
    //Improved Linear Search
    struct node *q;
    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct node * Rec_Lsearch(struct node *p, int key)
{
    if(p==NULL) return NULL;
    if(key == p->data) return p;
    return Rec_Lsearch(p->next,key);
}

void Insert(struct node *p, int index, int x)
{
    if(index<0 || index > count_Nodes(p))
     return;
    struct node *t = new node;
    t->data=x;
    if(index == 0)
    {
        t->next = first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void sortedInsert (struct node *p,int x)
{
    struct node *t, *q = NULL;
    t=new node;
    t->data = x;
    t->next=NULL;
    if(first == NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

int Delete_byIndex(struct node *p,int index)
{
    struct node *q;
    int x;
    if(index < 1 || index > count_Nodes(p))
        return -1;
    
    if(index == 1)
    {
        q=first;
        x=p->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int Delete_byValue(struct node *p,int val)
{
    int x;
    // while(p && p->data == val)
    // {
    //     p=p->next;

    // }
    if(p && p->data == val)
    {
        x=p->data;
        first=first->next;
        return x;
    }
    struct node *curr_node = p;
    while(curr_node && curr_node->next)
    {
        if(curr_node->next->data == val)
        {
            x=curr_node->next->data;
            curr_node->next = curr_node->next->next;
        }
        else
            curr_node=curr_node->next;
    }
    return x;

}

bool isSorted(struct node *p)
{
    int x = INT32_MIN;
    while(p)
    {
        if(p->data < x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

int main()
{
    int A[]={3,5,7,10,15};
    Create(A,5);
    Display(first);
    cout<<endl;
    recursive_Display(first);
    cout<<endl;
    cout<<"No. of Nodes in LL are: "<<count_Nodes(first);
    cout<<endl;
    cout<<"No. of Nodes using recursion in LL are: "<<recursive_count_Nodes(first);
    cout<<endl;
    cout<<"Sum of LL is: "<<sum(first);
    cout<<endl;
    cout<<"Sum using recursion of LL is: "<<recursive_Sum(first);
    cout<<endl;
    cout<<"Max among the LL is: "<<max(first);
    cout<<endl;
    cout<<"Recursive Max among the LL is: "<<rec_Max(first);
    cout<<endl;
    struct node *temp,*temp2;
    temp=Lsearch(first,10);
    if(temp)
        cout<<"Searching among the LL is: "<<temp->data<<" at Location "<<temp;
    else
        cout<<"Key not Found";
    cout<<endl;
    Display(first);
    cout<<endl;
    temp2 = Rec_Lsearch(first,5);
    if(temp2)
        cout<<"Recursive Searching among the LL is: "<<temp2->data<<" at Location "<<temp2;
    else
        cout<<"Key Not Found";

    cout<<endl;
    
    Insert(first,5,21);
    Display(first);
    cout<<endl;

    cout<<"Insert in sorted LL: ";
    sortedInsert(first,18);
    Display(first);
    cout<<endl;

    Delete_byIndex(first,3);
    cout<<"Delete by Index: ";
    Display(first);

    cout<<endl;

    Delete_byValue(first,10);
    cout<<"Delete by Value: ";
    Display(first);
    cout<<endl;

    cout<<"Sorted Status: "<<boolalpha<<isSorted(first);

    return 0;
}