/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 20:23
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

//Method-1: Tottoise-Hare Approach | Slow Fast ptr
ListNode* middleNode(ListNode *head){
    ListNode* slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* middleNode1(ListNode *head){
    ListNode *temp=head;
    //find length of ll
    int c=0;
    while(temp){
        c++; temp=temp->next;
    }
    for(int i=0;i< floor(c/2);i++)
        head=head->next;
    return head;
}
int main(){
    struct ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);    
    head->next->next = new ListNode(3);    
    head->next->next->next = new ListNode(4);    
    head->next->next->next->next = new ListNode(5); 
    head->next->next->next->next->next = new ListNode(6); 
    cout<<"Using slow fast ptr: "<<middleNode(head)->val<<endl;
    cout<<"Using Length of LL : "<<middleNode1(head)->val;
    return 0;
}