/*
Code by:Eeshan Chanpura
Coded on: 03-08-2022 21:03
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

ListNode* mergeTwoSortedList(ListNode *l1, ListNode *l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val > l2->val) swap(l1,l2);
    ListNode *res = l1;
    while(l1 && l2){
        ListNode *temp=NULL;
        while(l1 && l1->val <= l2->val){
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return res;
}

int main(){
    struct ListNode *l1, *l2;
    l1= new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *ans, *itr1=l1,*itr2=l2;
    cout<<"List 1: ";
    while(itr1){
        cout<<itr1->val<<" ";
        itr1=itr1->next;
    }
    cout<<endl;
    cout<<"List 2: ";
    while(itr2){
        cout<<itr2->val<<" ";
        itr2=itr2->next;
    }
    cout<<endl;
    cout<<"After merging two sorted LL: ";
    ans = mergeTwoSortedList(l1,l2);
    while(ans){
        cout<<ans->val<<" ";
        ans=ans->next;
    }

    return 0;
}