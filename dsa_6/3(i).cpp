// Q3(i). Find the size of a Doubly Linked List
#include <iostream>
using namespace std;

struct Node { int data; Node *prev, *next; };
int main() {
    Node* head = new Node{1, NULL, NULL};
    head->next = new Node{2, head, NULL};
    head->next->next = new Node{3, head->next, NULL};

    int size = 0;
    for (Node* t = head; t; t = t->next) size++;
    cout << "Size of DLL = " << size;
}
