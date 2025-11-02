#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    int k=4;
    Node* head=NULL; Node* tail=NULL;
    for(int i=1;i<=8;i++){
        Node* n=new Node{i,NULL};
        if(!head) head=n; else tail->next=n;
        tail=n;
    }

    Node* t=head; int len=1;
    while(t->next){ t=t->next; len++; }
    t->next=head; // make circular
    k%=len;
    for(int i=0;i<k;i++) head=head->next;
    t=head;
    for(int i=1;i<len;i++) t=t->next;
    t->next=NULL;

    t=head;
    while(t){ cout<<t->data<<"->"; t=t->next; }
    cout<<"NULL";
}
