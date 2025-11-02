
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // create circular linked list: 20 → 100 → 40 → 80 → 60 → (back to head)
    Node* n1 = new Node{20, NULL};
    Node* n2 = new Node{100, NULL};
    Node* n3 = new Node{40, NULL};
    Node* n4 = new Node{80, NULL};
    Node* n5 = new Node{60, NULL};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;  // make it circular
    Node* head = n1;

    cout << "Circular Linked List: ";
    Node* t = head;
    if (head) {
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << head->data;  // repeat head value at end
    }
}
