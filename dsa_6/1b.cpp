// Circular Linked List Implementation with Insertion, Deletion, Search, and Display
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    Node* head = NULL;
    int ch, val, key;

    do {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1.Insert at Beginning\n2.Insert at End\n3.Insert After\n4.Insert Before\n";
        cout << "5.Delete a Node\n6.Search a Node\n7.Display\n0.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) { // Insert at beginning
            cout << "Enter value: "; cin >> val;
            Node* n = new Node{val, NULL};
            if (!head) { head = n; n->next = head; }
            else {
                Node* t = head;
                while (t->next != head) t = t->next;
                n->next = head;
                t->next = n;
                head = n;
            }
        }

        else if (ch == 2) { // Insert at end
            cout << "Enter value: "; cin >> val;
            Node* n = new Node{val, NULL};
            if (!head) { head = n; n->next = head; }
            else {
                Node* t = head;
                while (t->next != head) t = t->next;
                t->next = n;
                n->next = head;
            }
        }

        else if (ch == 3) { // Insert after
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Insert after which value? "; cin >> key;
            Node* t = head;
            do {
                if (t->data == key) break;
                t = t->next;
            } while (t != head);
            if (t->data != key) cout << "Not found!\n";
            else {
                cout << "Enter value to insert: "; cin >> val;
                Node* n = new Node{val, t->next};
                t->next = n;
            }
        }

        else if (ch == 4) { // Insert before
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Insert before which value? "; cin >> key;
            Node* t = head, *prev = NULL;
            do {
                if (t->data == key) break;
                prev = t;
                t = t->next;
            } while (t != head);
            if (t->data != key) cout << "Not found!\n";
            else {
                cout << "Enter value to insert: "; cin >> val;
                Node* n = new Node{val, t};
                if (t == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = n;
                    n->next = head;
                    head = n;
                } else prev->next = n;
            }
        }

        else if (ch == 5) { // Delete node
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Enter value to delete: "; cin >> key;
            Node* t = head, *prev = NULL;
            do {
                if (t->data == key) break;
                prev = t;
                t = t->next;
            } while (t != head);
            if (t->data != key) cout << "Not found!\n";
            else if (t == head && t->next == head) { delete head; head = NULL; }
            else if (t == head) {
                Node* last = head;
                while (last->next != head) last = last->next;
                last->next = head->next;
                delete head;
                head = last->next;
            } else { prev->next = t->next; delete t; }
        }

        else if (ch == 6) { // Search
            if (!head) { cout << "List empty!\n"; continue; }
            cout << "Enter value to search: "; cin >> key;
            Node* t = head; int pos = 1, found = 0;
            do {
                if (t->data == key) { cout << "Found at position " << pos << endl; found = 1; break; }
                t = t->next; pos++;
            } while (t != head);
            if (!found) cout << "Not found!\n";
        }

        else if (ch == 7) { // Display
            if (!head) { cout << "Empty\n"; continue; }
            Node* t = head;
            cout << "CLL: ";
            do {
                cout << t->data << " -> ";
                t = t->next;
            } while (t != head);
            cout << head->data << " (repeat)\n";
        }

    } while (ch != 0);
}
