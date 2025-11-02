#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    // create two lists with intersection
    Node* common = new Node{8, new Node{10, NULL}};
    Node* head1 = new Node{3, new Node{7, common}};
    Node* head2 = new Node{99, new Node{1, common}};

    Node* a = head1; Node* b = head2;
    while (a != b) {
        a = a ? a->next : head2;
        b = b ? b->next : head1;
    }
    if (a) cout << "Intersected at node with value: " << a->data;
    else cout << "No intersection";
}
