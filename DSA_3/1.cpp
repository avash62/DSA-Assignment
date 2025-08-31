#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) cout << "Stack Overflow\n";
    else stack[++top] = x;
}

void pop() {
    if (top == -1) cout << "Stack Underflow\n";
    else cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (top == -1) cout << "Stack Empty\n";
    else cout << "Top element: " << stack[top] << endl;
}

void display() {
    if (top == -1) cout << "Stack Empty\n";
    else {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}
