/*
Code by:Eeshan Chanpura
Cooded on: 31-05-2022 22:00
*/
#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Using Stack
void reorderList(ListNode* head) {
        stack<ListNode*> S;
        ListNode *curr=head;
        while(curr){
            S.push(curr);
            curr=curr->next;
        }
        int n=S.size();
        curr=head;
        ListNode* nxt;
        
        if(n<=2) return;
        for(int i=0;i<n/2;++i){
            nxt=curr->next;
            curr->next=S.top(); S.pop();
            curr=curr->next;
            curr->next=nxt;
            curr=curr->next;
        }
        curr->next=nullptr;
    }

// Approach 2 : By reversing after middle and merging the two lists

int main(){

    return 0;
}