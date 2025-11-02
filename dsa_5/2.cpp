// Q2. Count occurrences of a given key and delete all of them
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    Node* head = NULL; Node* tail = NULL;
    int arr[] = {1,2,1,2,1,3,1};
    for (int i=0;i<7;i++) {
        Node* n = new Node{arr[i], NULL};
        if (!head) head = n;
        else tail->next = n;
        tail = n;
    }

    cout << "Original List: ";
    Node* t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;

    int key = 1, count = 0;

    // Remove leading nodes with key
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Remove other nodes
    t = head;
    while (t && t->next) {
        if (t->next->data == key) {
            Node* del = t->next;
            t->next = t->next->next;
            delete del;
            count++;
        } else t = t->next;
    }

    cout << "Count of deleted nodes: " << count << endl;
    cout << "Updated List: ";
    t = head;
    while (t) { cout << t->data << " "; t = t->next; }
}
