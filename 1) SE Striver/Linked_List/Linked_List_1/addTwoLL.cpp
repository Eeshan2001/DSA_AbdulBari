/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 22:42
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

ListNode* addTwoLL(ListNode* l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;
    while(l1 || l2 || carry){
        int sum = 0;
        if(l1){sum += l1->val; l1=l1->next;}
        if(l2){sum += l2->val; l2=l2->next;}
        sum += carry;
        carry = sum/10;
        ListNode *node = new ListNode(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
}

int main(){
    struct ListNode *l1;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);    
    l1->next->next = new ListNode(3);    
    ListNode *itr1 = l1;
    cout<<"List 1: ";
    while(itr1){
        cout<<itr1->val<<" ";
        itr1=itr1->next;
    }   
    cout<<endl;
    struct ListNode *l2;
    l2 = new ListNode(5);
    l2->next = new ListNode(6);    
    l2->next->next = new ListNode(4);    
    l2->next->next->next = new ListNode(9);    
    ListNode *itr2 = l2;
    cout<<"List 2: ";
    while(itr2){
        cout<<itr2->val<<" ";
        itr2=itr2->next;
    }   
    cout<<endl;

    ListNode *ans = addTwoLL(l1,l2);
    cout<<"After Adding two numbers: ";
    while(ans){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}