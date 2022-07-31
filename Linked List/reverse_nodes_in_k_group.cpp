/*
Code by:Eeshan Chanpura
Cooded on: 29-05-2022 20:57
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

ListNode* reversekgroup(ListNode* head,int k){
    if(head==NULL || k==1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next=head;
    ListNode *curr=dummy, *pre=dummy, *nxt=dummy;
    //count total nodes
    int count=0;
    while(curr->next){
        curr=curr->next;
        count++;
    }
    while(count>=k){
        curr=pre->next;
        nxt=curr->next;
        for(int i=1;i<k;i++){
            curr->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
            nxt=curr->next;
        }
        pre=curr;
        count-=k;
    }
    return dummy->next;
}

int main(){
    ListNode *head=new ListNode(1);
    ListNode*temp=head;
    for(int i=0;i<8;i++){
        int a;
        cin>>a;
        temp=temp->next;
        temp->val=a;
    }
    ListNode* res=reversekgroup(head,3);
    while(res->next){
        cout<<res->val<<"->";
        res=res->next;
    }
    cout<<res;
    return 0;
}