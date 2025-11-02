// Q1. For Doubly Linked List, implement insertion at beginning, insertion at end, insertion after a given node, insertion before a given node, deletion of a given node, searching for a given node, and displaying the list.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

int main() {
    Node* head = NULL;
    int ch, val, key;

    do {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1.Insert at Beginning\n2.Insert at End\n3.Insert After\n4.Insert Before\n";
        cout << "5.Delete a Node\n6.Search a Node\n7.Display\n0.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: "; cin >> val;
            Node* n = new Node{val, NULL, head};
            if (head) head->prev = n;
            head = n;
        }

        else if (ch == 2) {
            cout << "Enter value: "; cin >> val;
            Node* n = new Node{val, NULL, NULL};
            if (!head) head = n;
            else {
                Node* t = head;
                while (t->next) t = t->next;
                t->next = n;
                n->prev = t;
            }
        }

        else if (ch == 3) {  // Insert after
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Insert after which value? "; cin >> key;
            Node* t = head;
            while (t && t->data != key) t = t->next;
            if (!t) cout << "Not found!\n";
            else {
                cout << "Enter value to insert: "; cin >> val;
                Node* n = new Node{val, t, t->next};
                if (t->next) t->next->prev = n;
                t->next = n;
            }
        }

        else if (ch == 4) {  // Insert before
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Insert before which value? "; cin >> key;
            Node* t = head;
            while (t && t->data != key) t = t->next;
            if (!t) cout << "Not found!\n";
            else {
                cout << "Enter value to insert: "; cin >> val;
                Node* n = new Node{val, t->prev, t};
                if (t->prev) t->prev->next = n;
                else head = n;
                t->prev = n;
            }
        }

        else if (ch == 5) {  // Delete node
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Enter value to delete: "; cin >> key;
            Node* t = head;
            while (t && t->data != key) t = t->next;
            if (!t) cout << "Not found!\n";
            else {
                if (t->prev) t->prev->next = t->next;
                else head = t->next;
                if (t->next) t->next->prev = t->prev;
                delete t;
                cout << "Deleted.\n";
            }
        }

        else if (ch == 6) {  // Search
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Enter value to search: "; cin >> key;
            Node* t = head; int pos = 1, found = 0;
            while (t) {
                if (t->data == key) { cout << "Found at position " << pos << endl; found = 1; break; }
                pos++; t = t->next;
            }
            if (!found) cout << "Not found!\n";
        }

        else if (ch == 7) {  // Display
            if (!head) cout << "List empty!\n";
            else {
                cout << "DLL: ";
                Node* t = head;
                while (t) { cout << t->data << " <-> "; t = t->next; }
                cout << "NULL\n";
            }
        }

    } while (ch != 0);
}

