// Q3(ii). Find the size of a Circular Linked List
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
int main() {
    Node* head = new Node{1, NULL};
    Node* n2 = new Node{2, NULL};
    Node* n3 = new Node{3, NULL};
    head->next = n2; n2->next = n3; n3->next = head;

    int size = 0; Node* t = head;
    do { size++; t = t->next; } while (t != head);
    cout << "Size of CLL = " << size;
}
