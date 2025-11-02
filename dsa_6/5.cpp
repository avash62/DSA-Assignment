// Q5. Check if a linked list is circular or not
#include <iostream>
using namespace std;
struct Node { int data; Node* next; };
int main() {
    Node* n1 = new Node{2, NULL};
    Node* n2 = new Node{4, NULL};
    Node* n3 = new Node{6, NULL};
    n1->next = n2; n2->next = n3; n3->next = n1;

    Node* t = n1;
    bool circular = false;
    while (t && t->next) {
        t = t->next;
        if (t == n1) { circular = true; break; }
    }
    cout << (circular ? "Circular" : "Not Circular");
}
