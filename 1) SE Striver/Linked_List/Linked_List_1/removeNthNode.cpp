/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 21:34
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
ListNode* removeNthNode(ListNode *head,int n){
    ListNode * start = new ListNode();
    start -> next = head;
    ListNode* fast = start;
    ListNode* slow = start;     

    for(int i = 1; i <= n; ++i)
        fast = fast->next;
    
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}

// Method-2: Using Length
ListNode* removeNthNode2(ListNode *head,int n){
    // calculate length
    ListNode *temp=head; int c=0;
    while(temp){ c++; temp=temp->next;}
    int diff = c-n;
    if(diff == n ) return head->next;
    ListNode* ptr = head;
    for(int i=0;i<diff-1;i++) ptr=ptr->next;
    ptr->next=ptr->next->next;
    return head;
}

int main(){
    struct ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);    
    head->next->next = new ListNode(3);    
    head->next->next->next = new ListNode(4);    
    head->next->next->next->next = new ListNode(5); 
     
    cout<<"Using slow fast ptr: ";
    ListNode* res = removeNthNode(head,2);
    while(res){
        cout<<res->val<<" ";
        res=res->next;
    }cout<<endl;

    cout<<"Using Length of LL : ";
    ListNode *res1 = removeNthNode2(head,3);
    while(res1){cout<<res1->val<<" "; res1=res1->next;}
    cout<<endl;
    return 0;
}