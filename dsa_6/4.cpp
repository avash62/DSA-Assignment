// Q4. Check if a given string is a palindrome using Doubly Linked List

#include <iostream>
using namespace std;

struct Node { char data; Node *prev, *next; };
int main() {
    string s = "madam";
    Node* head = NULL; Node* tail = NULL;

    for (char c : s) {
        Node* n = new Node{c, tail, NULL};
        if (!head) head = n;
        else tail->next = n;
        tail = n;
    }

    Node* left = head; Node* right = tail;
    bool isPal = true;
    while (left && right && left != right && right->next != left) {
        if (left->data != right->data) { isPal = false; break; }
        left = left->next; right = right->prev;
    }
    cout << (isPal ? "Palindrome" : "Not Palindrome");
}
