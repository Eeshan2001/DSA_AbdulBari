/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 19:19
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL(ListNode* head){
    ListNode* newNode = NULL;
    while(head){
        ListNode* next = head->next;
        head->next = newNode;
        newNode=head;
        head=next;
    }
    return newNode;
}
ListNode* reverseList_recursion(ListNode* head) {
    if(head || head->next)
        return head;
    ListNode *nnode = reverseList_recursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return nnode;
}

ListNode* reverseList(ListNode* head) {
    struct ListNode *q=NULL,*r=NULL;
    while(head)
    {
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
    return q;
}

int main(){
    struct ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);    
    head->next->next = new ListNode(3);    
    head->next->next->next = new ListNode(4);    
    head->next->next->next->next = new ListNode(5); 
    cout<<"Before reversal of LL: ";
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }   
    cout<<endl;
    ListNode *res = reverseList(head);
    cout<<"After reversal of LL : ";
    while(res){
        cout<<res->val<<" ";
        res=res->next;
    }
    cout<<endl;
    
    ListNode *ans = reverseList_recursion(head);
    cout<<"After reversal of LL using recursion: ";
    while(ans){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}