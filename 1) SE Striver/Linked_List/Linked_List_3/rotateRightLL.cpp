/*
Code by:Eeshan Chanpura
Coded on: 04-08-2022 23:30
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int x) {
            val = x;
            next = NULL;
        }
};

void insertNode(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

ListNode* rotateRight(ListNode* head, int k){
    //edge case
    if(!head || !head->next || k==0)
        return head;
    //compute length
    int len=1; ListNode* curr = head;
    while(curr->next && ++len) curr=curr->next;
        
    // go till that node
    curr->next = head;
    k=k%len;
    k=len-k;
    while(k--)curr=curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
}

int main() {
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    ListNode* res = rotateRight(head,2);
    while(res) {cout<<res->val<<" "; res=res->next;}
    return 0;
}