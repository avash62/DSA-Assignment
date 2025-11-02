// Q3. Find the middle element of the linked list
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    Node* head = NULL; Node* tail = NULL;
    for (int i=1;i<=5;i++) {
        Node* n = new Node{i,NULL};
        if (!head) head = n;
        else tail->next = n;
        tail = n;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element is: " << slow->data;
}
