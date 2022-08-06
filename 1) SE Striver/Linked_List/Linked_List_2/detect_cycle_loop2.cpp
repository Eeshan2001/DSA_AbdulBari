#include<bits/stdc++.h>
using namespace std;

class Listnode {
    public:
        int val;
        Listnode* next;
        Listnode(int x) {
            val = x;
            next = NULL;
        }
};

void insertNode(Listnode* &head,int val) {
    Listnode* newNode = new Listnode(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Listnode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void createCycle(Listnode* &head,int pos) {
    Listnode* ptr = head;
    Listnode* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}
//Method -1 : Using hashset
Listnode* detectCycle(Listnode* head) {
    unordered_set<Listnode*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}
// Method-2: Using slow and fast pointer
Listnode* detectCycle2(Listnode* head){
    Listnode* slow = head, *fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    Listnode* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,10);
    
    createCycle(head,2);
    
    Listnode* nodeRecieve = detectCycle2(head);
    if(nodeRecieve == NULL) cout<<"No cycle";
    else {
        Listnode* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
    
    return 0;
}