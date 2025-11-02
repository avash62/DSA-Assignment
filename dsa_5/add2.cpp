#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    int k = 3;
    Node* head = NULL; Node* tail = NULL;
    for (int i=1;i<=9;i++) {
        Node* n = new Node{i,NULL};
        if (!head) head=n; else tail->next=n;
        tail=n;
    }

    Node* cur = head; Node* prev = NULL; Node* next = NULL;
    Node* newHead = NULL; Node* lastTail = NULL;

    while (cur) {
        int count=0; Node* groupHead = cur; prev=NULL;
        while (cur && count<k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        if (!newHead) newHead = prev;
        if (lastTail) lastTail->next = prev;
        lastTail = groupHead;
    }
    head = newHead;

    Node* t=head;
    while(t){ cout<<t->data<<"->"; t=t->next;}
    cout<<"NULL";
}
