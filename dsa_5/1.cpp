#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    int ch, val;

    do {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete from Beginning";
        cout << "\n4. Delete from End";
        cout << "\n5. Display";
        cout << "\n0. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter value: ";
                cin >> val;
                Node* n = new Node{val, head};
                head = n;
                break;
            }

            case 2: {
                cout << "Enter value: ";
                cin >> val;
                Node* n = new Node{val, NULL};
                if (head == NULL) head = n;
                else {
                    Node* t = head;
                    while (t->next != NULL) t = t->next;
                    t->next = n;
                }
                break;
            }

            case 3: {
                if (head == NULL) cout << "List empty\n";
                else {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                break;
            }

            case 4: {
                if (head == NULL) cout << "List empty\n";
                else if (head->next == NULL) {
                    delete head;
                    head = NULL;
                } else {
                    Node* t = head;
                    while (t->next->next != NULL) t = t->next;
                    delete t->next;
                    t->next = NULL;
                }
                break;
            }

            case 5: {
                Node* t = head;
                if (!t) cout << "List empty\n";
                else {
                    cout << "Linked List: ";
                    while (t != NULL) {
                        cout << t->data << " -> ";
                        t = t->next;
                    }
                    cout << "NULL\n";
                }
                break;
            }
        }
    } while (ch != 0);
}
