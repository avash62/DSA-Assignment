// Q4. Reverse a linked list
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    Node* head = NULL; Node* tail = NULL;
    for (int i=1;i<=4;i++) {
        Node* n = new Node{i,NULL};
        if (!head) head = n;
        else tail->next = n;
        tail = n;
    }

    cout << "Original: ";
    Node* t = head;
    while (t) { cout << t->data << "->"; t = t->next; }
    cout << "NULL\n";

    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;

    cout << "Reversed: ";
    t = head;
    while (t) { cout << t->data << "->"; t = t->next; }
    cout << "NULL";
}
