/*
Code by:Eeshan Chanpura
Created on: 01-02-2022 20:09
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node* insert(struct node *head,int co, int ex)
{
    struct node *temp;
    struct node *newp = new node;
    newp->coeff=co;
    newp->expo=ex;
    newp->next=NULL;

    // if no node in the list 0r given exponent is bigger than the first node->exp
    if(head == NULL || ex > head->expo)
    {
        newp->next = head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->next != NULL && temp->next->expo >=ex)
            temp=temp->next;
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}

struct node* create(struct node* head)
{
    int n,coeff,expo;
    cout<<"Enter the number of terms: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter each term coefficient and expo: ";
        cin>>coeff>>expo;
        head = insert(head, coeff, expo);
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
        cout<<"No polynomial.";
    else
    {
        struct node* temp=head;
        while(temp != NULL)
        {
            cout<<temp->coeff<<"x^"<<temp->expo;
            temp=temp->next;
            if(temp!=NULL)
                cout<<"+";
        }
    }
}

void poly_add(struct node* head1, struct node* head2)
{
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) 
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = insert(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->next;
    }
    cout<<"\nAddition is: ";
    display(head3);
}

void poly_sub(struct node* head1, struct node* head2)
{
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) 
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff - ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = insert(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->next;
    }
    cout<<"\nSubstraction is: ";
    display(head3);
}

void poly_multiply(struct node* head1, struct node* head2)
{
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    if(head1 == NULL || head2 == NULL)
    {
        cout<<"Zero polynomial.";
        return;
    }

    while(ptr1)
    {
        while(ptr2)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    // remove or modify or add duplicate expo
    struct node* ptr3 = head3;
    struct node* temp = NULL;

    while(ptr3->next)
    {
        if(ptr3->expo == ptr3->next->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->next->coeff;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
        }
        else{
            ptr3 = ptr3->next;
        }
    }
    cout<<"\nMultiplication is : ";
    display(head3);
}

int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    cout<<"-------------------Enter first polynomial------------------------\n";
    head1 = create(head1);
    cout<<"-------------------Enter second polynomial-----------------------\n";
    head2 = create(head2);
    cout<<"\nFirst polynomial is: ";
    display(head1);
    cout<<"\nSecond polynomial is: ";
    display(head2);
    poly_multiply(head1,head2);
    poly_add(head1,head2);
    poly_sub(head1,head2);
    return 0;
}